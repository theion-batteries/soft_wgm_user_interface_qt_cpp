# Use an official Windows Server Core image as the base image
FROM mcr.microsoft.com/windows:ltsc2019
# Set environment variables for the versions of software to be installed
ENV QT_VERSION=6.4.0
ENV GIT_VERSION=2.30.1
ENV CMAKE_VERSION=3.20.3
ENV NINJA_VERSION=1.10.2
ENV PERL_VERSION=5.32.0
# Install Git
#RUN powershell -Command \
#    $ErrorActionPreference = 'Stop'; \
#    Invoke-WebRequest https://github.com/git-for-windows/git/releases/download/v%GIT_VERSION%.windows.1/PortableGit-%GIT_VERSION%-64-bit.7z.exe -OutFile PortableGit.exe ; \
#    Start-Process -FilePath PortableGit.exe -ArgumentList '/SILENT' -Wait

# Install CMake
#RUN powershell -Command \
#    $ErrorActionPreference = 'Stop'; \
#    Invoke-WebRequest https://github.com/Kitware/CMake/releases/download/v%CMAKE_VERSION%/cmake-%CMAKE_VERSION%-win64-x64.msi -OutFile cmake.msi ; \
#    Start-Process -FilePath cmake.msi -ArgumentList '/quiet' -Wait

# Install Ninja
RUN powershell -Command \
    $ErrorActionPreference = 'Stop'; \
    Invoke-WebRequest https://github.com/ninja-build/ninja/releases/download/v%NINJA_VERSION%/ninja-win.zip -OutFile ninja.zip ; \
    Expand-Archive ninja.zip -DestinationPath C:\ninja ; \
    setx /M PATH $($env:PATH + ';C:\ninja')

# Install Visual Studio 2022
RUN powershell -Command \
    $ErrorActionPreference = 'Stop'; \
    Invoke-WebRequest https://aka.ms/vs/16/release/vs_community.exe -OutFile vs_community.exe ; \
    Start-Process -FilePath vs_community.exe -ArgumentList '--quiet --norestart --wait --nocache --add Microsoft.VisualStudio.Workload.VCTools' -Wait

# Install the C++ Build Tools
RUN powershell -Command \
    $ErrorActionPreference = 'Stop'; \
    Add-WindowsCapability -Online -Name "OpenSSH.Server~~~~0.0.1.0" ; \
    Install-WindowsFeature -Name "VisualStudio.BuildTools.VC.Tools.x86.x64"

# ...

# Clone the Qt repository
RUN git clone git://code.qt.io/qt/qt5.git qt6

# Switch to the v6.4.0 branch
RUN cd qt6 && git switch %QT_VERSION%

# Run the init-repository script
RUN cd qt6 && perl init-repository

# Create a build directory
RUN mkdir qt6-build

# Change to the build directory
WORKDIR qt6-build

# Configure the build with the prefix set to C:\path\to\install
RUN ..\qt6\configure.bat -prefix C:\path\to\install

# Build the project
RUN cmake --build .

# Install the project
RUN cmake --install .


ENV QTDIR C:\Qt\6.4.0\msvc2019_64
# Set the working directory
WORKDIR /app
# Copy the application files
COPY . .
