cmake_minimum_required(VERSION 3.3)
project(averager)
#FIND_PACKAGE(Boost)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

find_package(Boost COMPONENTS program_options REQUIRED)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()



# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)


set(AVERAGER_SOURCES main.cpp averager.h averager.cpp)

add_executable(averager ${AVERAGER_SOURCES} ${WORKER_SOURCES} )

add_test(averager example_test COMMAND example)
target_include_directories(averager PRIVATE ${BOOST_INCLUDE_DIRS})

target_link_libraries(averager gtest_main pthread ${Boost_LIBRARIES})

install(TARGETS averager RUNTIME DESTINATION bin)
