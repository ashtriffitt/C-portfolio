cmake_minimum_required(VERSION 3.23)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp Ant.cpp Ant.h Organism.cpp Organism.h Grid.cpp Grid.h MaleDoodlebug.cpp MaleDoodlebug.h FemaleDoodlebug.cpp FemaleDoodlebug.h)
