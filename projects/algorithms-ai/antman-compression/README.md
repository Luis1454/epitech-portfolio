# Antman — Multi-Format Lossless Data Compression

Custom lossless data compression and decompression engine targeting text, HTML, and PBM image data via dictionary encoding and frequency-based bit packing.

## Technical Overview

- **Primary Stack:** C, Data Compression, Bitwise Encoding
- **Core Language:** C

## Key Architecture & Features

- Domain-specific compression pipelines for plain text, structured markup, and image bitmaps
- Byte-level packing and Huffman-inspired dictionary lookup
- Guaranteed byte-accurate decompression fidelity

## Build & Execution

```sh
make
./antman/antman file.txt 1 > compressed.bin
./giantman/giantman compressed.bin 1 > restored.txt
```
