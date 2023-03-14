cmake_minimum_required(VERSION 3.1.0)

project(wgmApp 
DESCRIPTION "gui app created and maintained by sami dhiab"
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

 
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "${VCPKG_ROOT}/installed/x64-windows/share")

#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(yaml-cpp CONFIG REQUIRED)


file(GLOB PROJECT_SOURCES
        mainwindow.ui
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(wgmApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(wgmApp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(wgmApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

set_target_properties(wgmApp  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

target_link_libraries(wgmApp  PUBLIC Qt${QT_VERSION_MAJOR}::Core
PUBLIC Qt${QT_VERSION_MAJOR}::Widgets
PUBLIC Qt${QT_VERSION_MAJOR}::Concurrent
PUBLIC yaml-cpp
PUBLIC controllerLib)

target_include_directories(wgmApp 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../controlLayer/
PUBLIC ${SOCKPP_INCLUDE_DIRS}
PUBLIC ${SOCKPP_LIBRARIES}

)

set_target_properties(wgmApp PROPERTIES
    WIN32_EXECUTABLE TRUE
)
copy_dlls_keyence_target_destination(wgmApp)
copy_dlls_meteor_target_destination(wgmApp)
copy_dlls_yaml_target_destination(wgmApp)

add_dependencies(wgmApp build_install_camera)
install(TARGETS wgmApp
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}

LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h" 
)
INSTALL(FILES ${files} DESTINATION include/wgmApp/)

message("CMAKE_RUNTIME_OUTPUT_DIRECTORY: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
CMAKE_INSTALL_BINDIR: ${CMAKE_INSTALL_BINDIR}
CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}
")
FILE(GLOB dlls "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/*.dll" )
install(FILES ${dlls} DESTINATION bin/debug/)

FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/includes/*.h" )
INSTALL(FILES ${files} DESTINATION include/coolingLib/)

find_path(yamldir NAMES yaml-cppd.dll HINTS ${VCPKG_ROOT}/installed/x64-windows/debug/bin REQUIRED)
install(FILES ${yamldir}/yaml-cppd.dll DESTINATION bin/debug/)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(wgmApp)
endif()

windeployqt(wgmApp ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${CMAKE_INSTALL_BINDIR})
