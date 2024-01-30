cmake_minimum_required(VERSION 3.20)

project(result_test)

enable_testing()

find_package(GTest REQUIRED)

function(add_test test_suit)
    message(${test_suit})
    add_executable(${test_suit} ${test_suit}.cpp)
    target_include_directories(${test_suit} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include ${GTEST_INCLUDE_DIRS})
    target_link_libraries(${test_suit} PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
endfunction()

add_test(result_creation_test)
add_test(result_map_test)
add_test(result_flatmap_test)