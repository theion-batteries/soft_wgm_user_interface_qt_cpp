FROM mcr.microsoft.com/windows/servercore:1809
LABEL Description="Windows Server Core development environment for Qbs with Qt, Chocolatey and various dependencies for testing Qbs modules and functionality"

# Disable crash dialog for release-mode runtimes
RUN reg add "HKLM\SOFTWARE\Microsoft\Windows\Windows Error Reporting" /v Disabled /t REG_DWORD /d 1 /f
RUN reg add "HKLM\SOFTWARE\Microsoft\Windows\Windows Error Reporting" /v DontShowUI /t REG_DWORD /d 1 /f

# Install VS from the website since chocolatey has broken .NET 4.8 (dotnetfx package) which is a
# dependency for the visualstudio2019buildtools package
RUN powershell -NoProfile -ExecutionPolicy Bypass -Command \
    Invoke-WebRequest "https://aka.ms/vs/16/release/vs_community.exe" \
    -OutFile "%TEMP%\vs_community.exe" -UseBasicParsing

RUN "%TEMP%\vs_community.exe"  --quiet --wait --norestart --noUpdateInstaller \
    --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 \
    --add Microsoft.VisualStudio.Component.Windows10SDK.18362

RUN powershell -NoProfile -ExecutionPolicy Bypass -Command \
    $Env:chocolateyVersion = '0.10.15' ; \
    $Env:chocolateyUseWindowsCompression = 'false' ; \
    "[Net.ServicePointManager]::SecurityProtocol = \"tls12, tls11, tls\"; iex ((New-Object System.Net.WebClient).DownloadString('http://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"

ARG QBS_VERSION=1.18.2
RUN choco install -y python && \
    choco install -y 7zip --version 19.0 && \
    choco install -y git --version 2.24.0 --params "/GitAndUnixToolsOnPath" && \
    choco install -y qbs --version %QBS_VERSION%

# for building the documentation
RUN pip install beautifulsoup4 lxml

# clcache for speeding up MSVC builds
ENV CLCACHE_DIR="C:/.ccache"
RUN certutil -generateSSTFromWU roots.sst && \
    certutil -addstore -f root roots.sst && \
    del roots.sst && \
    pip install --trusted-host=pypi.org \
        git+https://github.com/frerich/clcache.git@cae73d8255d78db8ba11e23c51fd2c9a89e7475b

########### Install Qt #############
ARG QT_VERSION=6.4.0
COPY scripts/install-qt.sh install-qt.sh

RUN bash -c "./install-qt.sh -d /c/Qt --version ${QT_VERSION} --toolchain win64_msvc2019_64 qtbase qtdeclarative qttools"
ENV QTDIR64=C:\\Qt\\${QT_VERSION}\\msvc2019_64

RUN bash -c "./install-qt.sh -d /c/Qt --version ${QT_VERSION} --toolchain win32_msvc2019 qtbase qtdeclarative qttools"
ENV QTDIR=C:\\Qt\\${QT_VERSION}\\msvc2019

RUN qbs setup-toolchains --detect && \
    qbs setup-qt %QTDIR64%/bin/qmake.exe qt64 && \
    qbs setup-qt %QTDIR%/bin/qmake.exe qt && \
    qbs config defaultProfile qt64