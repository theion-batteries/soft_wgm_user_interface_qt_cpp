find_package(Qt6Test REQUIRED)

add_executable(myQtests MyClassTest.cpp)
target_link_libraries(myQtests Qt6::Test)


# Define a CTest test
add_test(NAME myQtests COMMAND myQtests)

# Add the test to the default test target
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)


enable_testing()