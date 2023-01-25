############################
###### Cmake template ######
############################

# author: sami dhiab
# email: sami@theion.de
# 

cmake_minimum_required(VERSION 3.1.0)

project(wgm_pkg
        DESCRIPTION "wgm package installer created and maintained by sami dhiab"
        HOMEPAGE_URL "https://github.com/theionSami/soft_wgm_user_interface_qt_cpp"
        LANGUAGES CXX)
enable_testing()

set(CMAKE_OBJECT_PATH_MAX 300)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GENERATOR_FILE_NAME "")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>) 
set(CMAKE_INSTALL_BINDIR bin/$<CONFIG>)
message("setting CMAKE_RUNTIME_OUTPUT_DIRECTORY to: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("setting CMAKE_INSTALL_BINDIR to: ${CMAKE_INSTALL_BINDIR}")
include(cmake/Windeployqt.cmake)
set(VCPKG_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/vcpkg CACHE FILEPATH "${VCPKG_ROOT}")
message(" parent: vcpkg root folder: ${VCPKG_ROOT}")
set(VCPKG_TARGET_TRIPLET x64-windows) # or x86-windows if you're using 32-bit
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_ROOT}/installed/x64-windows/share")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_ROOT}/installed/x64-windows/debug/bin")
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_ROOT}/installed/x64-windows/bin")
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

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
add_definitions(-DWHS_CONFIG="${WHS_CONFIG_DIR}") 
add_definitions(-DCNT_CONFIG="${CNT_CONFIG_DIR}") 
add_definitions(-DPH_CONFIG="${PH_CONFIG_DIR}") 
message("whs config file passed: ${WHS_CONFIG_DIR}")
message("cnt config file passed: ${CNT_CONFIG_DIR}")
message("ph config file passed: ${PH_CONFIG_DIR}")

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(sockpp CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
add_subdirectory(dependencies)
add_subdirectory(src)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_GENERATOR "NSIS")
#set(CPACK_PACKAGE_ICON )
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/pkg")
set(CPACK_PACKAGE_VENDOR "Sami Dhiab")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_WELCOME "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_NSIS_MODIFY_PATH OFF) 
set(CPACK_PACKAGE_VERSION "")
set(CPACK_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION ON)
include(CPack)
