cmake_minimum_required(VERSION 3.5.0)

project(wgm_view VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH  "C:/Qt/6.4.0/msvc2019_64/lib/cmake/Qt6")

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


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )


# pass variable of config file
add_definitions(-DWHS_CONFIG="${WHS_CONFIG}") 

file(GLOB PROJECT_SOURCES
        mainwindow.ui
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(wgm_view
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(wgm_view SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(wgm_view
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(wgm_view PUBLIC Qt${QT_VERSION_MAJOR}::Core
PUBLIC Qt${QT_VERSION_MAJOR}::Widgets
PUBLIC Qt${QT_VERSION_MAJOR}::Concurrent
PUBLIC controller)

target_include_directories(wgm_view 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/app
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/businesslogic

)

set_target_properties(wgm_view PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS wgm_view
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(wgm_view)
endif()

