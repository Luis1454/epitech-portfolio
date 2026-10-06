# FASTAtools — Genomic Sequence Analysis & k-mer Toolkit

High-throughput bioinformatics command-line utility analyzing FASTA-formatted DNA and RNA sequences, computing k-mer frequencies, and detecting coding sequences.

## Technical Overview

- **Primary Stack:** C, Bioinformatics Algorithms, String Processing
- **Core Language:** C

## Key Architecture & Features

- Sequence cleanup, RNA transcription, and reverse complement calculation
- Open reading frame (ORF) extraction and amino acid translation
- k-mer frequency indexing and lexicographical sorting

## Build & Execution

```sh
make
./FASTAtools 1 < sequence.fasta
```
