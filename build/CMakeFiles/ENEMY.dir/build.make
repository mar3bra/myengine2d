# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/marc/Desktop/OpenGL engine/MyEngine2D/code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build"

# Include any dependencies generated for this target.
include CMakeFiles/ENEMY.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ENEMY.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ENEMY.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ENEMY.dir/flags.make

CMakeFiles/ENEMY.dir/Enemy.cpp.o: CMakeFiles/ENEMY.dir/flags.make
CMakeFiles/ENEMY.dir/Enemy.cpp.o: ../Enemy.cpp
CMakeFiles/ENEMY.dir/Enemy.cpp.o: CMakeFiles/ENEMY.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ENEMY.dir/Enemy.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ENEMY.dir/Enemy.cpp.o -MF CMakeFiles/ENEMY.dir/Enemy.cpp.o.d -o CMakeFiles/ENEMY.dir/Enemy.cpp.o -c "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/Enemy.cpp"

CMakeFiles/ENEMY.dir/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ENEMY.dir/Enemy.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/Enemy.cpp" > CMakeFiles/ENEMY.dir/Enemy.cpp.i

CMakeFiles/ENEMY.dir/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ENEMY.dir/Enemy.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/Enemy.cpp" -o CMakeFiles/ENEMY.dir/Enemy.cpp.s

# Object files for target ENEMY
ENEMY_OBJECTS = \
"CMakeFiles/ENEMY.dir/Enemy.cpp.o"

# External object files for target ENEMY
ENEMY_EXTERNAL_OBJECTS =

libENEMY.a: CMakeFiles/ENEMY.dir/Enemy.cpp.o
libENEMY.a: CMakeFiles/ENEMY.dir/build.make
libENEMY.a: CMakeFiles/ENEMY.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libENEMY.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ENEMY.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ENEMY.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ENEMY.dir/build: libENEMY.a
.PHONY : CMakeFiles/ENEMY.dir/build

CMakeFiles/ENEMY.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ENEMY.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ENEMY.dir/clean

CMakeFiles/ENEMY.dir/depend:
	cd "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/marc/Desktop/OpenGL engine/MyEngine2D/code" "/home/marc/Desktop/OpenGL engine/MyEngine2D/code" "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build" "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build" "/home/marc/Desktop/OpenGL engine/MyEngine2D/code/build/CMakeFiles/ENEMY.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ENEMY.dir/depend

