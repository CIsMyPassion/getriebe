cmake_minimum_required(VERSION 3.8)
project(getriebe)

set(BUILD_SHARED_LIBS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE getriebe_include CONFIGURE_DEPENDS "include/*.h")
file(GLOB_RECURSE getriebe_src CONFIGURE_DEPENDS "src/*.h" "src/*.c")
set(source ${getriebe_src} ${getriebe_include})

add_executable(getriebe ${source})

target_include_directories(getriebe PUBLIC "include")


source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${source})


if(MSVC)
  target_compile_options(getriebe PRIVATE /W4)
else()
  target_compile_options(getriebe PRIVATE -Wall -Wextra -pedantic)
endif()
