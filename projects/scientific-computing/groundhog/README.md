# Groundhog — Real-Time Financial & Environmental Trend Analysis

Real-time rolling telemetry stream processor detecting trend switches, standard deviations, and temperature switches across temporal data feeds.

## Technical Overview

- **Primary Stack:** Python 3, Time-Series Statistics, Signal Processing
- **Core Language:** Python

## Key Architecture & Features

- Rolling window temperature increase average (g) calculation
- Relative temperature evolution (r) calculation
- Standard deviation (s) estimation over sliding intervals
- Automatic trend switch anomaly detection

## Build & Execution

```sh
./groundhog 7
```
