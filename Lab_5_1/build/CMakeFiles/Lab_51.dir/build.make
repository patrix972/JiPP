# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\cmake-3.19.0-win64-x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\cmake-3.19.0-win64-x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build

# Include any dependencies generated for this target.
include CMakeFiles/Lab_51.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_51.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_51.dir/flags.make

CMakeFiles/Lab_51.dir/src/main.cpp.obj: CMakeFiles/Lab_51.dir/flags.make
CMakeFiles/Lab_51.dir/src/main.cpp.obj: CMakeFiles/Lab_51.dir/includes_CXX.rsp
CMakeFiles/Lab_51.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_51.dir/src/main.cpp.obj"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_51.dir\src\main.cpp.obj -c C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\src\main.cpp

CMakeFiles/Lab_51.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_51.dir/src/main.cpp.i"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\src\main.cpp > CMakeFiles\Lab_51.dir\src\main.cpp.i

CMakeFiles/Lab_51.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_51.dir/src/main.cpp.s"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\src\main.cpp -o CMakeFiles\Lab_51.dir\src\main.cpp.s

CMakeFiles/Lab_51.dir/src/Matrix.cpp.obj: CMakeFiles/Lab_51.dir/flags.make
CMakeFiles/Lab_51.dir/src/Matrix.cpp.obj: CMakeFiles/Lab_51.dir/includes_CXX.rsp
CMakeFiles/Lab_51.dir/src/Matrix.cpp.obj: ../src/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_51.dir/src/Matrix.cpp.obj"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_51.dir\src\Matrix.cpp.obj -c C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\src\Matrix.cpp

CMakeFiles/Lab_51.dir/src/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_51.dir/src/Matrix.cpp.i"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\src\Matrix.cpp > CMakeFiles\Lab_51.dir\src\Matrix.cpp.i

CMakeFiles/Lab_51.dir/src/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_51.dir/src/Matrix.cpp.s"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\src\Matrix.cpp -o CMakeFiles\Lab_51.dir\src\Matrix.cpp.s

# Object files for target Lab_51
Lab_51_OBJECTS = \
"CMakeFiles/Lab_51.dir/src/main.cpp.obj" \
"CMakeFiles/Lab_51.dir/src/Matrix.cpp.obj"

# External object files for target Lab_51
Lab_51_EXTERNAL_OBJECTS =

Lab_51.exe: CMakeFiles/Lab_51.dir/src/main.cpp.obj
Lab_51.exe: CMakeFiles/Lab_51.dir/src/Matrix.cpp.obj
Lab_51.exe: CMakeFiles/Lab_51.dir/build.make
Lab_51.exe: CMakeFiles/Lab_51.dir/linklibs.rsp
Lab_51.exe: CMakeFiles/Lab_51.dir/objects1.rsp
Lab_51.exe: CMakeFiles/Lab_51.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab_51.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_51.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_51.dir/build: Lab_51.exe

.PHONY : CMakeFiles/Lab_51.dir/build

CMakeFiles/Lab_51.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_51.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_51.dir/clean

CMakeFiles/Lab_51.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1 C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1 C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build C:\Users\Patryk\Desktop\visual_code\JiPP\Lab_5_1\build\CMakeFiles\Lab_51.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab_51.dir/depend

