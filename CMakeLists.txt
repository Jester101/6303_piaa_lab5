cmake_minimum_required(VERSION 3.5)

project(KMP)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab5 src/lab5.cpp src/kmp.cpp src/kmp.h)
add_executable(cycl src/sycl.cpp src/kmp.cpp src/kmp.h)

add_executable(Prefixtest test/Prefixtest.cpp src/kmp.cpp src/kmp.h)
add_executable(testKMP test/Kmptest.cpp src/kmp.cpp src/kmp.h)
add_executable(testCheckShift test/CyclicShiftTest.cpp src/kmp.cpp src/kmp.h)

#add_executable(compareSimpleVsKmp src/compareSimpleVsKmp.cpp)

target_link_libraries(Prefixtest ${GTEST_LIBRARIES} pthread)
target_link_libraries(testKMP ${GTEST_LIBRARIES} pthread)
target_link_libraries(testCheckShift ${GTEST_LIBRARIES} pthread)

add_test(Prefixtest "./Prefixtest")
add_test(TestPatternSearch "./testKMP")
add_test(TestCheckShift "./testCheckShift")
