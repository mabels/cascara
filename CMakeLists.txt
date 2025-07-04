cmake_minimum_required (VERSION 3.12.0)
project (Cascara)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Cascara_SOURCE_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_SYSTEM_NAME})
#SET(PROJECT_BINARY_DIR ${Tunator_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

if (${CMAKE_COMPILER_IS_GNUCXX})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -g")


#Only tested with versions 1.55 and 1.56
#find_package(Boost 1.54.0 COMPONENTS system regex coroutine context thread iostreams REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})

#if(APPLE)
#  set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
#endif()

if(NOT GITBASE)
  set(GITBASE https://github.com)
endif()


#include(CMakeLists-Simple-WebSocket.txt)
#include(CMakeLists-easyloggingpp.txt)
#include(CMakeLists-ipaddress.txt)
#include(CMakeLists-jsoncpp.txt)

#set(SIMPLEWEB_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/Simple-WebSocket-Server")
#TODO: add requirement for version 1.0.1g (can it be done in one line?)
#find_package(OpenSSL REQUIRED)
#include_directories(${OPENSSL_INCLUDE_DIR})
#include_directories(${SIMPLEWEB_INCLUDE_DIR})

find_package(Threads REQUIRED)
include_directories(.)


#set_target_properties(main PROPERTIES LINK_SEARCH_START_STATIC 1)
#set_target_properties(main PROPERTIES LINK_SEARCH_END_STATIC 1)
#set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#add_executable(main main.cpp tunator.cpp tun_device.cpp if_addrs_macos.cpp if_addrs_linux.cpp)
#add_dependencies(main SimpleWebSocketServer)
#add_dependencies(main jsoncpp)
#add_dependencies(main ipaddress)
#add_dependencies(main easyloggingpp)
##target_link_libraries(main ${jsoncpp_LIBRARY_DIR})
#target_link_libraries(main ${ipaddress_LIBRARIES})
#target_link_libraries(main ${jsoncpp_LIBRARIES})
#target_link_libraries(main ${Boost_LIBRARIES})
#target_link_libraries(main ${OPENSSL_LIBRARIES})
#target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})

enable_testing()
add_subdirectory(test)



set(CASCARA_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include/cascara" 
    CACHE PATH "The directory the headers are installed in")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

install(FILES src/cascara.hpp src/chai.hpp src/mocha.hpp
        DESTINATION "${CASCARA_INCLUDE_INSTALL_DIR}"
        COMPONENT dev)

export(PACKAGE ${PROJECT_NAME})

