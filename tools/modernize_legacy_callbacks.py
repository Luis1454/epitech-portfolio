#!/usr/bin/env python3
"""Make legacy Epitech callback declarations explicit for modern C compilers."""

from pathlib import Path


ROOT = Path(__file__).resolve().parents[1] / "projects"
TARGET_NAMES = {
    "my_apply_on_matching_nodes.c",
    "my_delete_nodes.c",
    "my_find_node.c",
    "mylist.h",
    "btree_insert_data.c",
    "btree_search_item.c",
    "btree.h",
}

REPLACEMENTS = (
    (
        "int (*f)(), void const *data_ref, int (*cmp)()",
        "int (*f)(void *), void const *data_ref, int (*cmp)(void const *, void const *)",
    ),
    ("int (*cmpf)()", "int (*cmpf)(void const *, void const *)"),
    ("int (*cmp)()", "int (*cmp)(void const *, void const *)"),
    ("int(*cmp)()", "int(*cmp)(void const *, void const *)"),
)


def main() -> int:
    changed_files = 0
    replacements = 0
    for path in ROOT.rglob("*"):
        if not path.is_file() or path.name not in TARGET_NAMES:
            continue
        original = path.read_text(encoding="utf-8", errors="ignore")
        updated = original
        for old, new in REPLACEMENTS:
            count = updated.count(old)
            if count:
                updated = updated.replace(old, new)
                replacements += count
        if updated != original:
            path.write_text(updated, encoding="utf-8")
            changed_files += 1
    print(f"modernized_files={changed_files} replacements={replacements}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
