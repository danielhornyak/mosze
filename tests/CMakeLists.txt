cmake_minimum_required(VERSION 3.0.0)
project(mosze VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()
include(CPack)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  copytextfromtxtfile
  copytextfromtxtfile.cc
)

target_link_libraries(
  copytextfromtxtfile
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(copytextfromtxtfile)
#ADD_TEST(copytextfromtxtc
#"${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target copytextfromtxtfile)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/story.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})