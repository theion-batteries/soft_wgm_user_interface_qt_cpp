@echo off

if "%1"=="" (
    echo Usage: create-refactor-branches.bat BRANCH_NAME
    exit /b 1
)

set branch_name=%1

echo Creating "%branch_name%" branch in parent/root repository...
git checkout -b %branch_name%

echo.
echo Creating "%branch_name%" branch in all submodules...
git submodule foreach git checkout -b %branch_name%

echo.
echo All "%branch_name%" branches created successfully!
