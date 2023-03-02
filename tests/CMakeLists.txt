find_package(Qt6Test REQUIRED)

add_executable(myQtests MyClassTest.cpp)
target_link_libraries(myQtests Qt6::Test)