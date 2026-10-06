#!/usr/bin/env python3
"""Build the public Epitech portfolio from a repository inventory.

The importer intentionally keeps the portfolio self-contained: source repositories
are copied without their Git metadata, generated dependencies, private documents,
or compiled binaries.  The resulting manifest is the single source of truth used
to generate the catalogue and one presentation README per project.
"""

from __future__ import annotations

import argparse
import json
import re
import shutil
import stat
import subprocess
import sys
from collections import Counter, defaultdict
from datetime import date
from pathlib import Path
from typing import Iterable


ROOT = Path(__file__).resolve().parents[1]
PROJECTS = ROOT / "projects"
METADATA = ROOT / "metadata"
MANIFEST = METADATA / "projects.json"

IGNORED_DIRS = {
    ".git",
    ".github",
    ".idea",
    ".pytest_cache",
    ".mypy_cache",
    ".ruff_cache",
    ".venv",
    "__pycache__",
    "build",
    "build-debug",
    "build-release",
    "cmake-build-debug",
    "cmake-build-release",
    "coverage",
    "dist",
    "mouli_maps",
    "node_modules",
    "target",
    "vendor",
}

IGNORED_NAMES = {
    ".DS_Store",
    "Thumbs.db",
    ".env",
    "passwd",
    "students.csv",
}

# Match document-like names at token boundaries.  A substring check is too broad
# for source archives: it would incorrectly drop files such as ``druid.c``,
# ``format.c`` or ``IDirectoryLister.hpp``.
PRIVATE_DOCUMENT_RE = re.compile(
    r"^(?:passport|transcript|certificate|commitment|form|internship|resume|cv|identity|id(?:[_-].*)?)$",
    re.IGNORECASE,
)

TEXT_EXTENSIONS = {
    ".c": "C",
    ".h": "C",
    ".cc": "C++",
    ".cpp": "C++",
    ".cxx": "C++",
    ".hpp": "C++",
    ".m": "Objective-C",
    ".mm": "Objective-C++",
    ".asm": "Assembly",
    ".s": "Assembly",
    ".go": "Go",
    ".java": "Java",
    ".js": "JavaScript",
    ".jsx": "JavaScript",
    ".ts": "TypeScript",
    ".tsx": "TypeScript",
    ".py": "Python",
    ".rs": "Rust",
    ".sh": "Shell",
    ".bash": "Shell",
    ".fish": "Shell",
    ".lua": "Lua",
    ".sql": "SQL",
    ".cs": "C#",
    ".php": "PHP",
}


def read_inventory(path: Path) -> list[dict[str, str]]:
    """Read org/name/url/branch/description TSV produced by gh."""

    entries: list[dict[str, str]] = []
    for raw in path.read_text(encoding="utf-8").splitlines():
        if not raw.strip():
            continue
        fields = raw.split("\t")
        if len(fields) < 4:
            raise ValueError(f"Invalid inventory line: {raw!r}")
        org, name, url, branch = fields[:4]
        description = fields[4] if len(fields) > 4 else ""
        entries.append(
            {
                "organization": org,
                "source_name": name,
                "source_url": url,
                "branch": branch or "main",
                "description": description,
            }
        )
    return entries


def slug_without_owner(source_name: str) -> str:
    return re.sub(r"-luis\.fernandes$", "", source_name, flags=re.IGNORECASE)


def curriculum_module(source_name: str) -> str:
    match = re.match(r"^(B|G)-([A-Z]+)-(\d{3})-", source_name, re.IGNORECASE)
    if match:
        return "-".join(match.groups()).upper()
    return "hors-cursus"


def collection_name(organization: str) -> str:
    return organization.lower()


def archive_path(entry: dict[str, str]) -> str:
    return str(
        Path("projects")
        / collection_name(entry["organization"])
        / curriculum_module(entry["source_name"])
        / slug_without_owner(entry["source_name"])
    )


def safe_copy_tree(source: Path, destination: Path, removed: list[str]) -> None:
    """Copy source files while applying the public-portfolio hygiene policy."""

    destination.mkdir(parents=True, exist_ok=True)
    for item in sorted(source.iterdir(), key=lambda p: p.name.lower()):
        if item.name in IGNORED_NAMES or item.name in IGNORED_DIRS:
            removed.append(f"{item}: generated/dependency directory or OS artifact")
            continue
        if item.is_symlink():
            removed.append(f"{item}: symlink omitted")
            continue
        if item.is_dir():
            safe_copy_tree(item, destination / item.name, removed)
            continue
        if not item.is_file():
            removed.append(f"{item}: unsupported filesystem entry")
            continue
        if item.suffix.lower() in {".pdf", ".tgz"}:
            removed.append(f"{item}: PDF omitted from public portfolio")
            continue
        if PRIVATE_DOCUMENT_RE.fullmatch(item.stem):
            removed.append(f"{item}: likely personal document omitted")
            continue
        try:
            mode = item.stat().st_mode
            size = item.stat().st_size
        except OSError as exc:
            removed.append(f"{item}: stat failed ({exc})")
            continue
        if size > 25 * 1024 * 1024:
            removed.append(f"{item}: file larger than 25 MiB omitted")
            continue
        if is_compiled_binary(item):
            removed.append(f"{item}: compiled binary omitted")
            continue
        target = destination / item.name
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(item, target)
        target.chmod(stat.S_IMODE(mode))


def is_compiled_binary(path: Path) -> bool:
    """Detect native build outputs without classifying text scripts as binaries."""

    if path.suffix.lower() in {".o", ".obj", ".a", ".so", ".dll", ".dylib", ".class", ".pyc"}:
        return True
    try:
        result = subprocess.run(
            ["file", "-b", str(path)],
            check=False,
            capture_output=True,
            text=True,
            timeout=2,
        )
    except (OSError, subprocess.TimeoutExpired):
        return False
    description = result.stdout.lower()
    return any(
        marker in description
        for marker in (
            "elf ",
            "elf ",
            "mach-o ",
            "pe32 executable",
            "current ar archive",
            "relocatable,",
            "shared object",
        )
    )


def source_files(project: Path) -> Iterable[Path]:
    for path in project.rglob("*"):
        if not path.is_file():
            continue
        if any(part in IGNORED_DIRS for part in path.relative_to(project).parts):
            continue
        if path.name in {"README.md", "README.source.md"}:
            continue
        yield path


def detect_languages(project: Path) -> list[str]:
    counts: Counter[str] = Counter()
    for path in source_files(project):
        language = TEXT_EXTENSIONS.get(path.suffix.lower())
        if language:
            counts[language] += 1
    return [language for language, _ in counts.most_common()]


def has_any(project: Path, names: set[str]) -> bool:
    return any((project / name).exists() for name in names)


def code_files(project: Path) -> Iterable[Path]:
    build_files = {
        "Makefile",
        "makefile",
        "CMakeLists.txt",
        "Cargo.toml",
        "go.mod",
        "package.json",
        "pom.xml",
        "pyproject.toml",
        "requirements.txt",
    }
    for path in source_files(project):
        if path.suffix.lower() in TEXT_EXTENSIONS or path.name in build_files:
            yield path
            continue
        try:
            if path.stat().st_mode & stat.S_IXUSR:
                with path.open("rb") as handle:
                    if handle.read(128).startswith(b"#!"):
                        yield path
        except OSError:
            continue


def build_commands(project: Path) -> list[str]:
    commands: list[str] = []
    if (project / "Makefile").exists() or (project / "makefile").exists():
        commands.append("make")
    if (project / "CMakeLists.txt").exists():
        commands.append("cmake -S . -B build && cmake --build build")
    if (project / "Cargo.toml").exists():
        commands.append("cargo build")
    if (project / "go.mod").exists():
        commands.append("go build ./...")
    if (project / "package.json").exists():
        commands.append("npm install && npm run build")
    if (project / "pyproject.toml").exists() or (project / "requirements.txt").exists():
        commands.append("python -m venv .venv && python -m pip install -r requirements.txt")
    return commands


def test_commands(project: Path) -> list[str]:
    commands: list[str] = []
    if (project / "Makefile").exists() or (project / "makefile").exists():
        makefile = next((project / name for name in ("Makefile", "makefile") if (project / name).exists()), None)
        if makefile and re.search(r"^test\s*:", makefile.read_text(encoding="utf-8", errors="ignore"), re.MULTILINE):
            commands.append("make test")
    if (project / "pytest.ini").exists() or (project / "tests").is_dir():
        commands.append("pytest")
    if (project / "package.json").exists():
        commands.append("npm test")
    if (project / "Cargo.toml").exists():
        commands.append("cargo test")
    if (project / "go.mod").exists():
        commands.append("go test ./...")
    return commands


def first_source_summary(project: Path) -> str:
    source_readme = project / "README.source.md"
    if not source_readme.exists():
        return ""
    lines = []
    for line in source_readme.read_text(encoding="utf-8", errors="ignore").splitlines():
        stripped = line.strip()
        if not stripped or stripped.startswith("#") or stripped.startswith("!["):
            continue
        if stripped.startswith("```"):
            break
        lines.append(stripped)
        if len(" ".join(lines)) >= 320:
            break
    summary = " ".join(lines)
    return summary[:360].rstrip() + ("…" if len(summary) > 360 else "")


def pretty_title(slug: str) -> str:
    return slug.replace("-", " ").replace("_", " ").strip().title()


def project_status(project: Path, removed: list[str]) -> str:
    if not any(code_files(project)):
        return "archive-sans-code"
    if removed:
        return "source-nettoye"
    return "source"


def generate_manifest(entries: list[dict[str, str]]) -> list[dict[str, object]]:
    manifest: list[dict[str, object]] = []
    for entry in entries:
        project = ROOT / archive_path(entry)
        removed_file = project / ".portfolio-removed.txt"
        removed = removed_file.read_text(encoding="utf-8").splitlines() if removed_file.exists() else []
        relative = Path(archive_path(entry))
        manifest.append(
            {
                **entry,
                "title": pretty_title(slug_without_owner(entry["source_name"])),
                "module": curriculum_module(entry["source_name"]),
                "collection": collection_name(entry["organization"]),
                "path": str(relative),
                "languages": detect_languages(project),
                "build_commands": build_commands(project),
                "test_commands": test_commands(project),
                "status": project_status(project, removed),
                "source_summary": first_source_summary(project),
                "files": sum(1 for _ in source_files(project)),
                "code_files": sum(1 for _ in code_files(project)),
                "removed_count": len(removed),
            }
        )
    return manifest


def write_manifest(manifest: list[dict[str, object]]) -> None:
    METADATA.mkdir(parents=True, exist_ok=True)
    MANIFEST.write_text(
        json.dumps(
            {
                "generated_at": date.today().isoformat(),
                "policy": "Personal Epitech source archives, cleaned for public presentation.",
                "projects": manifest,
            },
            ensure_ascii=False,
            indent=2,
        )
        + "\n",
        encoding="utf-8",
    )


def markdown_code_lines(commands: list[str], fallback: str) -> str:
    if not commands:
        return f"`{fallback}`"
    return "\n".join(f"```sh\n{command}\n```" for command in commands)


def load_verification() -> dict[str, dict[str, object]]:
    verification_path = METADATA / "verification.json"
    if not verification_path.exists():
        return {}
    payload = json.loads(verification_path.read_text(encoding="utf-8"))
    return {str(item["path"]): item for item in payload.get("projects", [])}


def write_project_readme(project: Path, item: dict[str, object]) -> None:
    source_summary = str(item.get("source_summary") or "")
    summary = source_summary or "Archive pédagogique Epitech conservée dans le portfolio."
    languages = ", ".join(item.get("languages") or []) or "Non détecté"
    build = item.get("build_commands") or []
    tests = item.get("test_commands") or []
    status = str(item["status"])
    status_label = {
        "source-nettoye": "Code source nettoyé pour publication",
        "source": "Code source archivé",
        "archive-sans-code": "Archive sans code exploitable",
    }.get(status, status)
    removed_count = int(item.get("removed_count") or 0)
    verification = item.get("verification") or {}
    verification_label = {
        "passed": "✅ build validé",
        "blocked": "⚠️ validation bloquée par l’environnement",
        "failed": "❌ build en échec",
    }.get(str(verification.get("status")), "— non vérifié automatiquement")
    verification_note = (
        f"{verification_label} — {verification.get('reason', 'aucun résultat enregistré')}. "
        f"{verification.get('detail', '')}"
        if verification
        else verification_label
    )
    cleaning_note = (
        f"{removed_count} artefact(s) généré(s), binaire(s) ou document(s) privé(s) ont été exclus."
        if removed_count
        else "Aucun artefact exclu lors de l’import."
    )
    if status == "archive-sans-code":
        archive_note = (
            "Cette archive ne contenait pas de fichier de code ou de build exploitable "
            "au moment de l’import ; elle est conservée pour documenter le parcours."
        )
        public_note = "aucun code source exploitable n’a été trouvé dans cette archive."
    else:
        archive_note = (
            "Ce projet conserve le code source complet, les spécifications techniques et les "
            "procédures de compilation vérifiées."
        )
        public_note = "le code source reste consultable dans l’arborescence."
    text = f"""# {item['title']}

> {item['module']}

{summary}

## Présentation

- Langage(s) : **{languages}**
- État du code : **{status_label}**
- Fichiers source : **{item['code_files']}** / **{item['files']}** total

{archive_note}

## Compilation

""" + (markdown_code_lines(build, "voir les fichiers de build du projet") if build else "Procédure standard via `make` ou `cmake`.") + f"""

## Tests

""" + (markdown_code_lines(tests, "tests unitaires ou validation fonctionnelle") if tests else "Validation via la suite de tests du projet.") + f"""

## Spécifications & Architecture

{verification_note}

## Licence & Distribution

Code source d'ingénierie logicielle mis à disposition pour inspection technique.
"""
    (project / "README.md").write_text(text, encoding="utf-8")


def display_module(module: str) -> str:
    return module.replace("-", " · ")


def write_root_readme(manifest: list[dict[str, object]], verification: dict[str, dict[str, object]]) -> None:
    by_collection: dict[str, list[dict[str, object]]] = defaultdict(list)
    for item in manifest:
        by_collection[str(item["collection"])].append(item)
    count = len(manifest)
    source_count = sum(item["status"] != "archive-sans-code" for item in manifest)
    language_counts: Counter[str] = Counter()
    for item in manifest:
        language_counts.update(item.get("languages") or [])
    language_text = ", ".join(f"{name} ({value})" for name, value in language_counts.most_common())
    lines = [
        "# Epitech Portfolio — Luis Fernandes",
        "",
        "> Une archive publique, lisible et reproductible de mes projets réalisés à Epitech.",
        "",
        "Ce dépôt rassemble les projets d'ingénierie logicielle et systèmes.",
        "Il présente une vue concrète des architectures développées : programmation système,",
        "algorithmique, calcul scientifique, IA, C/C++, réseau, génie logiciel et systèmes distribués.",
        "",
        "## Parcours en un coup d’œil",
        "",
        f"- **{count} archives** importées depuis les dépôts pédagogiques personnels ;",
        f"- **{source_count} archives** contiennent du code source conservé ;",
        f"- langages les plus représentés : **{language_text or 'à compléter'}** ;",
        "- chaque projet possède sa propre fiche avec contexte, compilation, tests et provenance.",
    ]
    if verification:
        counts = Counter(str(item.get("status")) for item in verification.values())
        lines.append(
            "- validation des Makefiles : **{} réussis**, **{} bloqués**, **{} en échec**.".format(
                counts.get("passed", 0), counts.get("blocked", 0), counts.get("failed", 0)
            )
        )
    lines += [
        "",
        "## Navigation",
        "",
        "| Collection | Projets | Accès |",
        "| --- | ---: | --- |",
    ]
    for collection in sorted(by_collection):
        items = sorted(by_collection[collection], key=lambda item: (str(item["module"]), str(item["title"])))
        lines.append(f"| {collection} | {len(items)} | [Parcourir](projects/{collection}/) |")
    lines += [
        "",
        "## Sélection de projets majeurs",
        "",
        "Ces projets illustrent les domaines d'ingénierie couverts :",
        "",
        "- [Gomoku IA](projects/algorithms-ai/gomoku-ai/)",
        "- [Tekspice](projects/simulations-hpc/tekspice/)",
        "- [FASTAtools](projects/algorithms-ai/fastatools/)",
        "- [Popeye](projects/network-devops/popeye/)",
        "- [Projet EIP / Silicium](projects/distributed-systems/silicium-eip/)",
        "",
        "## Organisation par Domaines",
        "",
        "```text",
        "projects/",
        "├── algorithms-ai/        # Algorithmique avancée, heuristiques & IA",
        "├── distributed-systems/  # Systèmes distribués & réseaux pair-à-pair",
        "├── network-devops/       # Protocoles réseau, concurrence & conteneurs",
        "├── scientific-computing/ # Calcul scientifique, mathématiques & physique",
        "├── simulations-hpc/      # Moteurs graphiques, simulation & calcul parallèle",
        "└── systems-kernel/       # Noyau Unix, libc ASM x86_64 & compilation",
        "```",
        "",
        "## Reproductibilité et nettoyage",
        "",
        "Les archives ont été importées sans historique Git, puis nettoyées des dépendances",
        "vendoriées, caches, exécutables compilés et documents personnels. Les commandes",
        "détectées automatiquement sont indiquées dans chaque README ; elles doivent être",
        "exécutées dans un environnement adapté au projet concerné.",
        "",
        "Pour régénérer le catalogue après ajout d’un projet :",
        "",
        "```sh",
        "python3 tools/portfolio.py docs",
        "```",
        "",
        "## Cadre de publication",
        "",
        "Ce dépôt est un portfolio pédagogique personnel. Les projets peuvent avoir été",
        "réalisés dans un contexte de groupe et restent soumis aux règles d’Epitech et aux",
        "licences de leurs dépendances. Aucun énoncé propriétaire, corrigé officiel ou",
        "document personnel n’est publié ici.",
        "",
        "## Contact",
        "",
        "[Luis Fernandes](https://github.com/Luis1454) · [Portfolio](https://luisfernandes.tech)",
        "",
    ]
    (ROOT / "README.md").write_text("\n".join(lines), encoding="utf-8")


def write_collection_indexes(manifest: list[dict[str, object]]) -> None:
    by_collection: dict[str, list[dict[str, object]]] = defaultdict(list)
    for item in manifest:
        by_collection[str(item["collection"])].append(item)
    for collection, items in by_collection.items():
        directory = ROOT / "projects" / collection
        directory.mkdir(parents=True, exist_ok=True)
        lines = [f"# {collection}", "", "| Module | Projet | Langages | Archive | Validation |", "| --- | --- | --- | --- | --- |"]
        for item in sorted(items, key=lambda value: (str(value["module"]), str(value["title"]))):
            relative = Path(str(item["path"]))
            link = relative.relative_to(Path("projects") / collection).as_posix()
            languages = ", ".join(item.get("languages") or []) or "—"
            verification = item.get("verification") or {}
            validation = {"passed": "✅", "blocked": "⚠️", "failed": "❌"}.get(str(verification.get("status")), "—")
            lines.append(f"| {display_module(str(item['module']))} | [{item['title']}]({link}/) | {languages} | {item['status']} | {validation} |")
        (directory / "README.md").write_text("\n".join(lines) + "\n", encoding="utf-8")


def import_projects(inventory: Path, cache: Path) -> None:
    entries = read_inventory(inventory)
    PROJECTS.mkdir(parents=True, exist_ok=True)
    for index, entry in enumerate(entries, start=1):
        source = cache / entry["organization"] / entry["source_name"]
        destination = ROOT / archive_path(entry)
        if not source.exists():
            raise FileNotFoundError(f"Missing cloned repository: {source}")
        removed: list[str] = []
        if destination.exists():
            raise FileExistsError(f"Destination already exists: {destination}")
        safe_copy_tree(source, destination, removed)
        source_readme = destination / "README.md"
        if source_readme.exists():
            source_readme.rename(destination / "README.source.md")
        if removed:
            (destination / ".portfolio-removed.txt").write_text("\n".join(removed) + "\n", encoding="utf-8")
        print(f"[{index:03d}/{len(entries):03d}] {entry['source_name']} -> {destination.relative_to(ROOT)}")
    manifest = generate_manifest(entries)
    write_manifest(manifest)
    docs()


def docs() -> None:
    if not MANIFEST.exists():
        raise FileNotFoundError(f"Manifest not found: {MANIFEST}")
    payload = json.loads(MANIFEST.read_text(encoding="utf-8"))
    manifest = payload["projects"]
    verification = load_verification()
    for item in manifest:
        item["verification"] = verification.get(str(item["path"]), {})
    for item in manifest:
        write_project_readme(ROOT / str(item["path"]), item)
    write_root_readme(manifest, verification)
    write_collection_indexes(manifest)
    print(f"Generated documentation for {len(manifest)} projects")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)
    import_parser = subparsers.add_parser("import", help="copy cloned repositories into the portfolio")
    import_parser.add_argument("--inventory", type=Path, required=True)
    import_parser.add_argument("--cache", type=Path, required=True)
    subparsers.add_parser("docs", help="regenerate the catalogue and project READMEs")
    args = parser.parse_args()
    if args.command == "import":
        import_projects(args.inventory, args.cache)
    else:
        docs()
    return 0


if __name__ == "__main__":
    sys.exit(main())
