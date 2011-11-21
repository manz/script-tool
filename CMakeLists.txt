cmake_minimum_required (VERSION 2.6)
project (Script-tool)

SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS "-ggdb -Wall -fblocks")

file(
	GLOB_RECURSE
	source_files
	script-tool/*.cpp
)

add_executable(script-tool-b ${source_files})
include_directories(script-tool-b "/usr/include/libxml2")

target_link_libraries (script-tool-b dispatch xml2)

