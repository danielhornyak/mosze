cmake_minimum_required(VERSION 3.0.0)
project(mosze VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(src main.cpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/story.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
