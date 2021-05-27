cmake_minimum_required(VERSION 3.7)
project(getriebe)

add_compile_options(-W -Wall)
add_compile_options(-g)
set(BUILD_SHARED_LIBS OFF)

file(GLOB_RECURSE getriebe_src CONFIGURE_DEPENDS "src/*.h" "src/*.c")
source_group("src" FILES ${getriebe_src})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output")
add_executable(getriebe ${getriebe_src} ${include_src})