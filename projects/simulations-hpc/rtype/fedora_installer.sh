#!/bin/bash

set -e

# Nom du projet et dossier de build
PROJECT_NAME="r-type_server"
BUILD_DIR="build"

# Vérification des droits root
if [ "$EUID" -ne 0 ]; then
  echo "Veuillez exécuter ce script avec les droits administrateur (sudo)." >&2
  exit 1
fi

echo "Mise à jour des paquets et installation des dépendances..."
sudo dnf update -y
sudo dnf install -y \
    @development-tools \
    cmake \
    g++ \
    asio-devel

echo "Configuration et compilation du projet..."

# Créer le dossier de build
if [ -d "$BUILD_DIR" ]; then
  echo "Nettoyage du dossier de build existant..."
  rm -rf "$BUILD_DIR"
fi
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

# Configuration CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Compilation
cmake --build . --target "$PROJECT_NAME" -- -j$(nproc)

# Installation de l'exécutable
INSTALL_DIR="/usr/local/bin"
sudo cp "$PROJECT_NAME" "$INSTALL_DIR/"

echo "Installation terminée !"
echo "Vous pouvez exécuter le serveur avec la commande : $PROJECT_NAME"
