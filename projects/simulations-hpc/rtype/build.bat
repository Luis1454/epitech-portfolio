@echo off
SETLOCAL ENABLEDELAYEDEXPANSION

:: 📌 Définition des chemins
set VCPKG_PATH=C:\vcpkg
set CMAKE_TOOLCHAIN_FILE=%VCPKG_PATH%\scripts\buildsystems\vcpkg.cmake
set BUILD_DIR=build
set DEPENDENCIES=asio sfml getpot

:: 📌 Vérifier si vcpkg est installé
if not exist "%VCPKG_PATH%\vcpkg.exe" (
    echo 🔍 vcpkg non trouvé. Installation...
    git clone https://github.com/microsoft/vcpkg.git %VCPKG_PATH%
    cd /d %VCPKG_PATH%
    bootstrap-vcpkg.bat
    cd /d %~dp0
) else (
    echo ✅ vcpkg est déjà installé.
)

:: 📌 Ajouter vcpkg au PATH temporairement
set PATH=%PATH%;%VCPKG_PATH%

:: 📌 Vérifier et installer les dépendances
echo 🔍 Vérification des dépendances...
for %%D in (%DEPENDENCIES%) do (
    echo 🔹 Vérification de %%D...
    %VCPKG_PATH%\vcpkg list | findstr /C:"%%D" >nul
    if %errorlevel% neq 0 (
        echo 📦 Installation de %%D...
        %VCPKG_PATH%\vcpkg install %%D:x64-windows
    ) else (
        echo ✅ %%D est déjà installé.
    )
)

:: 📌 Supprimer le dossier de build s'il existe
if exist %BUILD_DIR% (
    echo 🗑️ Suppression de l'ancien répertoire de build...
    rmdir /s /q %BUILD_DIR%
)

:: 📌 Exécution de CMake et compilation
echo ⚙️ Génération du projet avec CMake...
cmake -B %BUILD_DIR% -DCMAKE_TOOLCHAIN_FILE=%CMAKE_TOOLCHAIN_FILE%
if %errorlevel% neq 0 (
    echo ❌ Erreur lors de la génération avec CMake.
    exit /b 1
)

echo 🚀 Compilation du projet...
cmake --build %BUILD_DIR% --config Release
if %errorlevel% neq 0 (
    echo ❌ Erreur lors de la compilation.
    exit /b 1
)

echo 🎉 Installation et compilation terminées !
pause
