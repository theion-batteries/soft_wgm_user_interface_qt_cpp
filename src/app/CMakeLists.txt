cmake_minimum_required(VERSION 3.1.0)

project(wgm_app VERSION 0.1 LANGUAGES CXX)

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


# pass variable of config file
message("whs config file passed: ${WHS_CONFIG}")
add_definitions(-DWHS_CONFIG="${WHS_CONFIG}") 

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )


file(GLOB PROJECT_SOURCES
        mainwindow.ui
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(wgm_app
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(wgm_app SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(wgm_app
            ${PROJECT_SOURCES}
        )
    endif()
endif()

set_target_properties(wgm_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

target_link_libraries(wgm_app PUBLIC Qt${QT_VERSION_MAJOR}::Core
PUBLIC Qt${QT_VERSION_MAJOR}::Widgets
PUBLIC Qt${QT_VERSION_MAJOR}::Concurrent
PUBLIC controller)

target_include_directories(wgm_app 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/app
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/businesslogic

)

set_target_properties(wgm_app PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


install(TARGETS wgm_app
    RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}

    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h" 
)
INSTALL(FILES ${files} DESTINATION include/wgm_app/)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(wgm_app)
endif()

add_custom_command(TARGET wgm_app POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:wgm_app> $<TARGET_FILE_DIR:wgm_app>
  COMMAND_EXPAND_LISTS
  )
#windeployqt( wgm_app ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
# Retrieve the absolute path to qmake and then use that path to find
# the windeployqt executable
get_target_property(QMAKE_EXE Qt6::qmake IMPORTED_LOCATION)
get_filename_component(QT_BIN_DIR "${QMAKE_EXE}" DIRECTORY)

find_program(WINDEPLOYQT_ENV_SETUP qtenv2.bat HINTS "${QT_BIN_DIR}")
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_BIN_DIR}")

# Run windeployqt immediately after build
add_custom_command(TARGET wgm_app
    POST_BUILD
    COMMAND "${WINDEPLOYQT_ENV_SETUP}" && "${WINDEPLOYQT_EXECUTABLE}" \"$<TARGET_FILE:wgm_app>\"
)