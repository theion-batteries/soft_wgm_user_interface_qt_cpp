############################
###### Cmake template ######
############################

# author: sami dhiab
# email: sami@theion.de


cmake_minimum_required(VERSION 3.1.0)

project(wgm_pkg
        VERSION 0.1.0
        DESCRIPTION "created and maintained by sami dhiab"
        HOMEPAGE_URL "https://github.com/theionSami/soft_wgm_user_interface_qt_cpp"
        LANGUAGES CXX)
enable_testing()

include(cmake/Windeployqt.cmake)

set(CMAKE_OBJECT_PATH_MAX 300)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_INSTALL_BINDIR}) 

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# To enable mocking
#add_definitions(-DSINK_SENSOR_MOCK)  
#add_definitions(-DSINK_AXIS_MOCK)  
# pass variable of config file to subdir cpp file
message("add config file definition ${WHS_CONFIG} to application")
#add_definitions(-DWHS_CONFIG="${WHS_CONFIG}") 

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )

add_subdirectory(dependencies)
add_subdirectory(src)


set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "Sami Dhiab")
include(CPack)
