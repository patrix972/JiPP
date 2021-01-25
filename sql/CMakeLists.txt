cmake_minimum_required( VERSION 3.0 )
project( sql )
include_directories( src test include libs )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Matrix.cpp ./libs/sqlite3/sqlite3.c)
