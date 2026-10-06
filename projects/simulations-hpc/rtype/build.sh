#!/bin/bash

# 📌 Définition des variables
VCPKG_PATH="$HOME/vcpkg"
CMAKE_TOOLCHAIN_FILE="$VCPKG_PATH/scripts/buildsystems/vcpkg.cmake"
BUILD_DIR="build"
DEPENDENCIES=("asio" "sfml")

# 📌 Vérifier si vcpkg est installé
if [ ! -f "$VCPKG_PATH/vcpkg" ]; then
    echo "🔍 vcpkg non trouvé. Installation..."
    git clone https://github.com/microsoft/vcpkg.git "$VCPKG_PATH"
    cd "$VCPKG_PATH" || exit
    ./bootstrap-vcpkg.sh
    cd - || exit
else
    echo "✅ vcpkg est déjà installé."
fi

# 📌 Ajouter vcpkg au PATH temporairement
export PATH="$VCPKG_PATH:$PATH"

# 📌 Vérifier et installer les dépendances
echo "🔍 Vérification des dépendances..."
for dep in "${DEPENDENCIES[@]}"; do
    echo "🔹 Vérification de $dep..."
    if ! "$VCPKG_PATH/vcpkg" list | grep -q "$dep"; then
        echo "📦 Installation de $dep..."
        "$VCPKG_PATH/vcpkg" install "$dep:x64-linux"
    else
        echo "✅ $dep est déjà installé."
    fi
done

# 📌 Supprimer le dossier de build s'il existe
if [ -d "$BUILD_DIR" ]; then
    echo "🗑️ Suppression du répertoire de build existant..."
    rm -rf "$BUILD_DIR"
fi

# 📌 Générer et compiler avec CMake
echo "⚙️ Exécution de CMake..."
cmake -B "$BUILD_DIR" -DCMAKE_TOOLCHAIN_FILE="$CMAKE_TOOLCHAIN_FILE"
cmake --build "$BUILD_DIR" --config Release

echo "🎉 Compilation terminée !"