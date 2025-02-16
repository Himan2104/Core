cmake_minimum_required(VERSION 3.27)

project(Core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_definitions(CORE_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	add_compile_definitions(CORE_RELEASE)
endif()

add_library(core Source/Math/Utils.cpp)

target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/Include)

add_executable(tests Tests/Main.cpp)