cmake_minimum_required(VERSION 3.5)
project(ISTOGRAMMI)

set(SOURCES 
  src/bogo-sort.cpp
  src/bubble-sort.cpp
  src/coctail-sort.cpp
  src/easy-sort.cpp
  src/insertion-sort.cpp
  src/insertion-sort-recursive.cpp
  src/main.cpp
  src/merge-sort.cpp
  src/quick-sort.cpp
  src/selection-sort.cpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
