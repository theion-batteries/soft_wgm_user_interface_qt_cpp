#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )



file(GLOB PROJECT_SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )
add_library(controllerLib STATIC ${PROJECT_SOURCES}


)
target_link_libraries(controllerLib PUBLIC Qt6::Core 
                                 PUBLIC Qt6::Widgets
                                 PUBLIC Qt6::Concurrent
                                 PUBLIC modelLib
)

target_include_directories(controllerLib
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/modelLayer/

)

############################# install target lib ########################################
install(TARGETS keyenceLib DESTINATION lib)
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h" 
)
INSTALL(FILES ${files} DESTINATION include/keyenceLib/)