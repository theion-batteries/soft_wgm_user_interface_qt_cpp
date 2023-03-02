@echo off

if "%1"=="" (
    echo Usage: checkout_all_to_win_dev_api.bat BRANCH_NAME
    exit /b 1
)

set branch_name=%1

echo switching to "%branch_name%" branch in parent/root repository...
git checkout  %branch_name%

echo.
echo switching to "%branch_name%" branch in all submodules...
git submodule foreach --recursive git checkout  %branch_name%

echo.
echo All "%branch_name%" branches created successfully!
