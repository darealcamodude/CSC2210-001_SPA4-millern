cmake_minimum_required(VERSION 3.30)
project(wumpus)

set(CMAKE_CXX_STANDARD 20)

add_executable(wumpus
        src/Token.cpp
        src/Bat.cpp
        src/MapCell.cpp
        src/Map.cpp
        src/Player.cpp
        src/Wumpus.cpp
        src/Arrow.cpp
        src/Pit.cpp
        src/main.cpp)
