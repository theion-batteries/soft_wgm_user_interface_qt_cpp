#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# pass variable of config file
add_definitions(-DWHS_CONFIG="${WHS_CONFIG}") 

add_library(controller STATIC
    controller.cpp
    controller.h
)
target_link_libraries(controller PRIVATE Qt6::Core 
                                 PRIVATE Qt6::Widgets
                                 PUBLIC model
)

target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
