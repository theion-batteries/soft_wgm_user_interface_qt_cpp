############################
###### Cmake template ######
############################

# author: sami dhiab
# email: sami@theion.de


cmake_minimum_required(VERSION 3.5.0)

project(wgm_pkg VERSION 0.1 LANGUAGES CXX)

#set(CMAKE_PREFIX_PATH  "C:/Qt/6.4.0/msvc2019_64/lib/cmake/Qt6")
set(CMAKE_OBJECT_PATH_MAX 300)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

 
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
#add_definitions(-D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)  
# To enable mocking
add_definitions(-DSINK_SENSOR_MOCK)  
add_definitions(-DSINK_AXIS_MOCK)  

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_subdirectory(dependencies)
add_subdirectory(src)


include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "Sami Dhiab")
include(CPack)
