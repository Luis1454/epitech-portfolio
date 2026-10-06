# Popeye — Multi-Service Microservices Containerization

Enterprise multi-service voting application containerized using Docker, Docker Compose, and multi-stage container builds.

## Technical Overview

- **Primary Stack:** Docker, Docker Compose, Microservices, Python, Redis, Postgres, Node.js
- **Core Language:** Docker

## Key Architecture & Features

- Multi-tier architecture: Python web frontend, Redis queue, .NET worker, PostgreSQL database, Node.js result dashboard
- Multi-stage Dockerfiles optimizing image size and build caching
- Docker Compose network isolation and persistent volume configuration

## Build & Execution

```sh
docker-compose up --build
```
