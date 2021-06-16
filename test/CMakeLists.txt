cmake_minimum_required(VERSION 3.8)
project(test)

file(GLOB_RECURSE test_src CONFIGURE_DEPENDS "src/*.h" "src/*.c")

add_executable(${PROJECT_NAME} ${test_src})
add_dependencies(${PROJECT_NAME} getriebe)

target_link_libraries(${PROJECT_NAME} getriebe)
target_include_directories(test PRIVATE "${GETRIEBE_INCLUDE}")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${test_src})