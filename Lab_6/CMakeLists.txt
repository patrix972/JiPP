cmake_minimum_required( VERSION 3.0 )
project(Lab_6)
include_directories( ./include ./src )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/HRMS.cpp ./src/Employee.cpp )