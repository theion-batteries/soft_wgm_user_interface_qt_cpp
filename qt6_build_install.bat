git clone git://code.qt.io/qt/qt5.git qt6
cd qt6
git switch v6.4.0
cd qt6
perl init-repository
mkdir qt6-build
cd qt6-build
..\qt6\configure.bat -prefix C:
cmake --build .
cmake --install .