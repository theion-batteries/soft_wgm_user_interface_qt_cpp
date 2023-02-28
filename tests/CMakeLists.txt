include(FetchContent)


set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../src/viewLayer/)      
        
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Concurrent Test )

qt_add_executable(CntViewTest ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)



target_link_libraries(CntViewTest  PUBLIC Qt${QT_VERSION_MAJOR}::Core
PUBLIC Qt${QT_VERSION_MAJOR}::Widgets
PUBLIC Qt${QT_VERSION_MAJOR}::Concurrent
PUBLIC Qt${QT_VERSION_MAJOR}::Test
PUBLIC yaml-cpp
PUBLIC controllerLib)


target_include_directories(CntViewTest
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests/CntViewTest/
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src/viewLayer/
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src/controlLayer/
)

target_sources(CntViewTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/CntViewTest/CntViewTest.cpp)

set_target_properties(CntViewTest PROPERTIES WIN32_EXECUTABLE TRUE)

