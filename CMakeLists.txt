cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gameoflife LANGUAGES C)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(game)
add_subdirectory(gui)

target_include_directories(${PROJECT_NAME}
  PRIVATE game
  PRIVATE gui
  PUBLIC /usr/local/include
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} game gui SDL2)

