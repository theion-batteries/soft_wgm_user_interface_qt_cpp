#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# pass variable of config file
add_definitions(-DWHS_CONFIG="${WHS_CONFIG}") 

file(GLOB PROJECT_SOURCES
       "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        )
add_library(controller STATIC ${PROJECT_SOURCES}


)
target_link_libraries(controller PUBLIC Qt6::Core 
                                 PUBLIC Qt6::Widgets
                                 PUBLIC model
)

target_include_directories(controller
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../includes/businesslogic

)
