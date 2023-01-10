mkdir build 
cd build
cpack -C Debug 
cd ../pkg/
XCOPY "wgm_pkg.exe" "soft_wgm_installer_update\" /K /D /H /Y
cd soft_wgm_installer_update/
git add wgm_pkg.exe
git commit -m "updated installer"
git push 