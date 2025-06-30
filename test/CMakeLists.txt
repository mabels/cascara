cmake_minimum_required(VERSION 3.12.0)
project (cascaraTest)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${cascaraTest_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -DTEST")
if (${CMAKE_COMPILER_IS_GNUCXX})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -g")


#set(CMAKE_SHARED_LINKER_FLAGS="-lprofiler -ltcmalloc")


enable_testing()

#find_package(Boost 1.54.0 COMPONENTS system regex REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})

#find_package(Threads REQUIRED)

#set (PROJECT_LINK_LIBS libcascara.a)
#link_directories( ../${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME})

#add_executable(test_crunchy, test_crunchy.cpp)
#add_test(test_crunchy test_crunchy)

add_executable(test_cascara test_cascara.cpp)
add_test(test_cascara test_cascara)

