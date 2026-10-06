# Vérifie si l'utilisateur a les droits administratifs
if (-not ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Host "Ce script doit être exécuté en tant qu'administrateur." -ForegroundColor Red
    exit
}

# Fonction pour télécharger un fichier
function Download-File($url, $destination) {
    Write-Host "Téléchargement de $url vers $destination"
    Invoke-WebRequest -Uri $url -OutFile $destination -UseBasicParsing
}

# Chemins pour installer les outils
$installDir = "C:\DevTools"
$mingwUrl = "https://sourceforge.net/projects/mingw-w64/files/latest/download"
$cmakeUrl = "https://github.com/Kitware/CMake/releases/latest/download/cmake-3.27.0-windows-x86_64.msi"

# Crée le répertoire d'installation
if (!(Test-Path $installDir)) {
    New-Item -ItemType Directory -Path $installDir
}

# Téléchargement et installation de MinGW
$mingwInstaller = "$installDir\mingw.exe"
if (!(Test-Path $mingwInstaller)) {
    Download-File $mingwUrl $mingwInstaller
    Start-Process $mingwInstaller -ArgumentList "/S" -Wait
}

# Téléchargement et installation de CMake
$cmakeInstaller = "$installDir\cmake.msi"
if (!(Test-Path $cmakeInstaller)) {
    Download-File $cmakeUrl $cmakeInstaller
    Start-Process msiexec.exe -ArgumentList "/i", $cmakeInstaller, "/quiet", "/norestart" -Wait
}

# Ajout des outils aux variables d'environnement
$mingwPath = "$installDir\mingw\bin"
if (-not ($env:Path -split ';' | Where-Object { $_ -eq $mingwPath })) {
    [Environment]::SetEnvironmentVariable("Path", $env:Path + ";$mingwPath", [EnvironmentVariableTarget]::Machine)
    Write-Host "Chemin MinGW ajouté à la variable PATH."
}

# Vérification des installations
Write-Host "Vérification des outils installés..."
if (!(Get-Command "gcc" -ErrorAction SilentlyContinue)) {
    Write-Host "Erreur : GCC n'est pas installé ou accessible depuis PATH." -ForegroundColor Red
    exit
}

if (!(Get-Command "cmake" -ErrorAction SilentlyContinue)) {
    Write-Host "Erreur : CMake n'est pas installé ou accessible depuis PATH." -ForegroundColor Red
    exit
}

Write-Host "Les outils sont installés correctement." -ForegroundColor Green

# Chemin d'installation du projet (emplacement où Inno Setup a installé le programme)
$projectDir = $PSScriptRoot  # Utilise l'emplacement où le script est exécuté

# Crée un répertoire de build dans le répertoire d'installation du projet
$buildDir = Join-Path $projectDir "build"
if (!(Test-Path $buildDir)) {
    Write-Host "Création du répertoire de build..."
    mkdir $buildDir
}

# Compilation du projet
Write-Host "Configuration et compilation du projet..."
cd $buildDir
cmake .. -G "MinGW Makefiles"
cmake --build .

Write-Host "Compilation terminée !" -ForegroundColor Green
