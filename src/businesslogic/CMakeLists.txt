#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Concurrent )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent )

# pass variable of config file
add_definitions(-DWHS_CONFIG="${WHS_CONFIG}") 

file(GLOB PROJECT_SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )
add_library(controller STATIC ${PROJECT_SOURCES}


)
target_link_libraries(controller PUBLIC Qt6::Core 
                                 PUBLIC Qt6::Widgets
                                 PUBLIC Qt6::Concurrent
                                 PUBLIC model
)

target_include_directories(controller
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/businesslogic
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../dependencies/model

)

############################# install target lib ########################################
install(TARGETS keyence_lib_static DESTINATION lib)
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h" 
)
INSTALL(FILES ${files} DESTINATION include)