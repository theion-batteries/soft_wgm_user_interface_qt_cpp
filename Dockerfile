# Use the latest Windows Server Core image as the base image
FROM mcr.microsoft.com/windows/servercore:ltsc2022

# Install Git
#RUN powershell.exe -Command "Invoke-WebRequest -Uri 'https://github.com/git-for-windows/git/releases/download/v2.31.1.windows.1/Git-2.31.1-64-bit.exe' -OutFile 'git.exe'"
#RUN powershell.exe -Command "& 'git.exe' /VERYSILENT /NORESTART"

# Install Qt 6
RUN powershell.exe -Command "Invoke-WebRequest -Uri 'https://download.qt.io/official_releases/qt/6.4/6.4.0/single/qt-everywhere-src-6.4.0.zip' -OutFile 'qt.zip'"
RUN powershell.exe -Command "Expand-Archive -Path 'qt.zip' -DestinationPath 'C:\Qt'"
RUN powershell.exe -Command "& 'C:\Qt\qt-opensource-windows-x86-6.4.0.exe' /VERYSILENT /NORESTART"
ENV QTDIR C:\Qt\6.4.0\msvc2019_64

# Set the working directory
WORKDIR /app

# Copy the application files
COPY . .
