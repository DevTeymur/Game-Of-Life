cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

project(gui)


add_library(${PROJECT_NAME} entity.c entity.h map.c map.h screen.c screen.h)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include) 

# target_include_directories(${PROJECT_NAME} PUBLIC usr/lib) 
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_directories(${PROJECT_NAME} PUBLIC /usr/local/lib)
# find_package(SDL2 REQUIRED)
# find_package(SDL2image REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
# target_link_libraries( ${PROJECT_NAME} PUBLIC SDL2)


