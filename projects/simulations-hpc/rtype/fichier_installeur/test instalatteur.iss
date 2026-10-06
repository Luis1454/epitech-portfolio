; Script de base pour créer un installateur
[Setup]
AppName=Projet Hello
AppVersion=1.0
DefaultDirName={pf}\ProjetHello
DefaultGroupName=Projet Hello
OutputDir=Output
OutputBaseFilename=setup-hello
Compression=lzma
SolidCompression=yes

[Files]
; Inclure tous les fichiers du projet
Source: "C:\Users\Lyso\Downloads\cpp\B-CPP-500-LIL-5-2-rtype-salman.rezki\*"; DestDir: "{app}"; Flags: recursesubdirs
Source: "C:\Users\Lyso\Downloads\cpp\B-CPP-500-LIL-5-2-rtype-salman.rezki\CMakeLists.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Lyso\Downloads\cpp\B-CPP-500-LIL-5-2-rtype-salman.rezki\README.md"; DestDir: "{app}"; Flags: ignoreversion


[Icons]
; Ajouter un raccourci vers le script setup.ps1
Name: "{group}\Projet Hello"; Filename: "powershell.exe"; Parameters: "-ExecutionPolicy Bypass -File ""{app}\setup.ps1"""

[Run]
; Exécuter automatiquement le script PowerShell après installation
Filename: "powershell.exe"; Parameters: "-ExecutionPolicy Bypass -File ""{app}\setup.ps1"""; Flags: shellexec waituntilterminated
