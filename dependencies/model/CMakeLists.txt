add_library(model STATIC
    model.cpp
    model.h
    sinkingModel.h
    sinkingModel.cpp
)
target_link_libraries(model PRIVATE Qt6::Core 
                            PUBLIC wgm_static)

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../software_wgm_v2_cpp/includes)


#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()