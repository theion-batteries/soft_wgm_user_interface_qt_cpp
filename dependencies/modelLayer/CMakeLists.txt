add_library(modelLib STATIC
    model.cpp
    model.h
    sinkingModel.h
    sinkingModel.cpp
    cntAlignModel.h
    cntAlignModel.cpp
    mainModel.h
    mainModel.cpp
    heatingModel.h
    heatingModel.cpp
    extractingModel.h
    extractingModel.cpp
    coolingModel.h
    coolingModel.cpp
)
target_link_libraries(modelLib PUBLIC Qt6::Core 
                            PUBLIC wgmCoreLib)

target_include_directories(modelLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../software_wgm_v2_cpp/includes)


#This is necessary for MSVC to create a symbol file, .lib, besides a shared library, .dll
if (MSVC)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

install(TARGETS modelLib DESTINATION lib)
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
INSTALL(FILES ${files} DESTINATION include/model/)