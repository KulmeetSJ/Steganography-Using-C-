cmake_minimum_required(VERSION 3.0.0)
project(cvtest VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )

add_executable(cvtest encode.cpp )

include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(cvtest ${OpenCV_LIBS} )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD REQUIRED ON )





