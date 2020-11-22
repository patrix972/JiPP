cmake_minimum_required( VERSION 3.0 )
project( Lab_4 )
include_directories( ./include ./src ./libs ./tests )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Matrix.cpp)