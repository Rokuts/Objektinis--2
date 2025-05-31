# Pagrindinė informacija
Outfile "ObjektinisSetup.exe"
InstallDir "$PROGRAMFILES\VU\Rokas-Venckus"
InstallDirRegKey HKCU "Software\VU\RVenckus" "Install_Dir"

# Langai
Page directory
Page instfiles
UninstPage uninstConfirm
UninstPage instfiles

# Instaliavimo sekcija
Section "Instaliuoti"

  # Sukuriam instaliacijos katalogą
  CreateDirectory "$INSTDIR"

  # Nukopijuojam failus
  SetOutPath "$INSTDIR"
  File "build\Objektinis.exe"

  # Sukuriam uninstallerį
  WriteUninstaller "$INSTDIR\uninstall.exe"

  # Sukuriam nuorodą darbalaukyje
  CreateShortCut "$DESKTOP\Rokas-Venckus.lnk" "$INSTDIR\Objektinis.exe"

  # Sukuriamas start meniu linkas
  CreateDirectory "$SMPROGRAMS\VU"
  CreateShortCut "$SMPROGRAMS\VU\Rokas-Venckus.lnk" "$INSTDIR\Objektinis.exe"

  # Išsaugom instaliacijos vietą registre
  WriteRegStr HKCU "Software\VU\RVenckus" "Install_Dir" "$INSTDIR"

  # Įrašom pašalinimo informaciją į valdymo skydą (Add/Remove Programs)
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\Rokas-Venckus" "DisplayName" "Rokas Venckus Programa"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\Rokas-Venckus" "UninstallString" "$INSTDIR\uninstall.exe"

SectionEnd

# Pašalinimo sekcija
Section "Uninstall"

  # Trinam failus
  Delete "$INSTDIR\Objektinis.exe"
  Delete "$INSTDIR\uninstall.exe"
  Delete "$DESKTOP\Rokas-Venckus.lnk"

  # Trinam katalogą
  RMDir "$INSTDIR"

  Delete "$SMPROGRAMS\VU\Rokas-Venckus.lnk"
  RMDir "$SMPROGRAMS\VU"

  # Trinam registro reikšmes
  DeleteRegKey HKCU "Software\VU\RVenckus"
  DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\Rokas-Venckus"

SectionEnd

