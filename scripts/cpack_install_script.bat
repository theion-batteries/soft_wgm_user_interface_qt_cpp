cd ..
mkdir build 
cd build
cpack -C Debug -v
cd ../pkg/
XCOPY "wgm_pkg.exe" "soft_wgm_installer_update\" /K /D /H /Y
XCOPY "wgm_application_user_manual.pdf" "soft_wgm_installer_update\" /K /D /H /Y
cd soft_wgm_installer_update/
git add wgm_pkg.exe
git add wgm_application_user_manual.pdf
git commit -m "updated installer"
git log --pretty=oneline -n 10
git push
REM git push https://${{ secrets.GITHUB_TOKEN }}@github.com/theion-batteries/soft_wgm_installer_update.git