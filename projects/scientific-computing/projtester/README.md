# ProjTester — Automated Binary Integration Testing Framework

Automated black-box test runner validating binary standard output, error streams, and exit codes against expected reference specifications.

## Technical Overview

- **Primary Stack:** C, Testing Frameworks, Process Sandboxing
- **Core Language:** C

## Key Architecture & Features

- Test suite file parsing and process isolation
- Execution timeout detection avoiding infinite loops
- Diff comparison and colored terminal pass/fail summary

## Build & Execution

```sh
make
./projtester test_suite.txt
```
