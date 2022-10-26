add_library(controller STATIC
    controller.cpp
    controller.h
)
target_link_libraries(controller PRIVATE Qt6::Core
                                 PUBLIC model
)

target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
