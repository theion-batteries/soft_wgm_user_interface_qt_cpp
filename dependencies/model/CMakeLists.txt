add_library(model STATIC
    model.cpp
    model.h
)
target_link_libraries(model PRIVATE Qt6::Core 
                            PUBLIC wgm_static)

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../software_wgm_v2_cpp/includes)