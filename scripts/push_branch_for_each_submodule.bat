@echo off

if "%1"=="" (
    echo Usage: create_branch_for_each_submodule.bat BRANCH_NAME
    exit /b 1
)

set branch_name=%1
cd ..
echo Pushing changes in "%branch_name%" 
git push origin %branch_name%

echo.
cd dependencies
git push origin %branch_name%
echo Creating "%branch_name%" branch in all submodules...

cd software_wgm_v2_cpp
git submodule foreach --recursive git push origin %branch_name%

echo.
REM echo All "%branch_name%" branches created successfully!
