cmake_minimum_required(VERSION 3.10)
project(Snake)

set(CMAKE_CXX_STANDARD 14)

# Including the SFML libraries. 
set(SFML_INCLUDE_DIR "/home/jio/.local/include/sfml/include")
set(SFML_LIBRARY_DIR "/home/jio/.local/include/sfml/lib")
set(SFML_DIR "/home/jio/.local/include/sfml/lib/cmake/SFML")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
	message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
	message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARY_DIR}")
	message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()
# enf of including SFML libraries

# Sources

include_directories(include)

set(SOURCES
	src/main.cpp
	src/food.cpp
	src/snake.cpp
	)

set(HEADERS
	include/snake.hpp
	include/food.hpp
	)

add_executable(Snake ${SOURCES} ${HEADERS})
target_link_libraries(Snake sfml-graphics sfml-window sfml-system)

