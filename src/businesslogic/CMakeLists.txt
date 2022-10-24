add_library(controller STATIC
    controller.cpp
    controller.h
)
target_link_libraries(controller PRIVATE Qt6::Core)
target_include_directories(controller INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})