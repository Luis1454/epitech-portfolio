#!/usr/bin/env python3
"""Compile the projects that expose a top-level Makefile in isolated copies."""

from __future__ import annotations

import json
import re
import shutil
import subprocess
import tempfile
from datetime import date
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "metadata" / "projects.json"
OUTPUT = ROOT / "metadata" / "verification.json"


def classify(returncode: int | None, output: str, timed_out: bool) -> tuple[str, str]:
    if timed_out:
        return "blocked", "timeout après 45 secondes"
    if returncode == 0:
        return "passed", "make terminé avec succès"
    lowered = output.lower()
    if any(
        marker in lowered
        for marker in (
            "no such file or directory",
            "command not found",
            "nasm: not found",
            "ncurses.h: no such file",
            "sfml/graphics.h: no such file",
        )
    ):
        return "blocked", "dépendance ou outil absent dans l’environnement de validation"
    if "no rule to make target" in lowered:
        return "failed", "source requis absent dans l’archive"
    return "failed", "erreur de compilation dans le code ou le Makefile"


def compact_detail(output: str) -> str:
    for raw_line in output.splitlines():
        line = raw_line.strip()
        if not line:
            continue
        if re.search(r"fatal error:|error:|no rule to make target|command not found|not found", line, re.I):
            line = re.sub(r"/tmp/[^ :]+", "<temporary-build>", line)
            return line[:240]
    for raw_line in reversed(output.splitlines()):
        line = raw_line.strip()
        if line:
            return line[:240]
    return "aucune sortie"


def copy_for_build(source: Path, destination: Path) -> None:
    ignored = shutil.ignore_patterns(
        ".git",
        ".portfolio-removed.txt",
        "*.o",
        "*.a",
        "*.so",
        "*.dylib",
        "*.dll",
        "build",
        "coverage",
        "node_modules",
        "__pycache__",
    )
    shutil.copytree(source, destination, ignore=ignored)


def main() -> int:
    payload = json.loads(MANIFEST.read_text(encoding="utf-8"))
    projects = payload["projects"]
    results: list[dict[str, object]] = []
    with tempfile.TemporaryDirectory(prefix="epitech-portfolio-build-") as temporary:
        build_root = Path(temporary)
        for item in projects:
            commands = item.get("build_commands") or []
            if "make" not in commands:
                continue
            source = ROOT / str(item["path"])
            destination = build_root / str(item["path"])
            destination.parent.mkdir(parents=True, exist_ok=True)
            copy_for_build(source, destination)
            try:
                completed = subprocess.run(
                    ["make"],
                    cwd=destination,
                    capture_output=True,
                    text=True,
                    timeout=45,
                    check=False,
                )
                output = (completed.stdout or "") + (completed.stderr or "")
                status, reason = classify(completed.returncode, output, False)
                returncode: int | None = completed.returncode
                timed_out = False
            except subprocess.TimeoutExpired as exc:
                output = (exc.stdout or "") + (exc.stderr or "")
                status, reason = classify(None, output, True)
                returncode = None
                timed_out = True
            results.append(
                {
                    "path": item["path"],
                    "source_name": item["source_name"],
                    "command": "make",
                    "status": status,
                    "reason": reason,
                    "detail": "" if status == "passed" else compact_detail(output),
                    "returncode": returncode,
                    "timed_out": timed_out,
                }
            )
            print(f"{status:7} {item['path']}")
    counts: dict[str, int] = {}
    for result in results:
        status = str(result["status"])
        counts[status] = counts.get(status, 0) + 1
    OUTPUT.write_text(
        json.dumps(
            {
                "generated_at": date.today().isoformat(),
                "scope": "top-level Makefile projects",
                "summary": counts,
                "projects": results,
            },
            ensure_ascii=False,
            indent=2,
        )
        + "\n",
        encoding="utf-8",
    )
    print(f"summary={counts}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
