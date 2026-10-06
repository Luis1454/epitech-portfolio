# SBML Parser — Systems Biology Markup Language Analyzer

XML lexical parser and analyzer for Systems Biology Markup Language (SBML) files, extracting biochemical species, compartments, and kinetic reactions.

## Technical Overview

- **Primary Stack:** C, XML Parsing, Computational Biology
- **Core Language:** C

## Key Architecture & Features

- XML tag hierarchy traversal without heavyweight external libraries
- Extraction of species, reactions, reactant and product stoichiometry
- Reaction formula reconstruction and consistency verification

## Build & Execution

```sh
make
./SBMLparser model.sbml
```
