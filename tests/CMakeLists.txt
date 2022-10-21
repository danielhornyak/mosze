cmake_minimum_required(VERSION 3.0.0)
project(mosze VERSION 0.1.0)
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
#gtest_discover_tests(copytextfromtxtfile)

file(COPY ${CMAKE_BINARY_DIR}/src/story.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
ADD_TEST(ctest_build_test_code
"${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target copytextfromtxtfile)