############################
###### Cmake template ######
############################

# author: sami dhiab
# email: sami@theion.de


cmake_minimum_required(VERSION 3.5)

project(wgm_ui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH  "C:/Qt/6.4.0/msvc2019_64/lib/cmake/Qt6")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_subdirectory(src/app)
#add_subdirectory(src/businesslogic)
