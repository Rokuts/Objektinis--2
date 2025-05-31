cmake_minimum_required(VERSION 3.14)

project(Objektinis VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB SOURCES "src/*.cpp" "src/*.h")
file(GLOB SOURCES_TEST "tests/*.cpp" "tests/*.h")

add_executable(Objektinis ${SOURCES} main.cpp)
target_include_directories(Objektinis PRIVATE ${CMAKE_SOURCE_DIR}/src)

enable_testing()

add_executable(
  Objektinis_test
  ${SOURCES_TEST}
  ${SOURCES}
)
target_include_directories(Objektinis_test PRIVATE ${CMAKE_SOURCE_DIR}/src) 
target_link_libraries(
  Objektinis_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Objektinis_test)