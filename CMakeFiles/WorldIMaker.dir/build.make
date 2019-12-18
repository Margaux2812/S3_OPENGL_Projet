# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/margaux/Documents/S3_OPENGL_Projet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/margaux/Documents/S3_OPENGL_Projet

# Include any dependencies generated for this target.
include CMakeFiles/WorldIMaker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WorldIMaker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WorldIMaker.dir/flags.make

CMakeFiles/WorldIMaker.dir/src/cube.cpp.o: CMakeFiles/WorldIMaker.dir/flags.make
CMakeFiles/WorldIMaker.dir/src/cube.cpp.o: src/cube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/margaux/Documents/S3_OPENGL_Projet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WorldIMaker.dir/src/cube.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WorldIMaker.dir/src/cube.cpp.o -c /home/margaux/Documents/S3_OPENGL_Projet/src/cube.cpp

CMakeFiles/WorldIMaker.dir/src/cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WorldIMaker.dir/src/cube.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/margaux/Documents/S3_OPENGL_Projet/src/cube.cpp > CMakeFiles/WorldIMaker.dir/src/cube.cpp.i

CMakeFiles/WorldIMaker.dir/src/cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WorldIMaker.dir/src/cube.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/margaux/Documents/S3_OPENGL_Projet/src/cube.cpp -o CMakeFiles/WorldIMaker.dir/src/cube.cpp.s

CMakeFiles/WorldIMaker.dir/src/main.cpp.o: CMakeFiles/WorldIMaker.dir/flags.make
CMakeFiles/WorldIMaker.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/margaux/Documents/S3_OPENGL_Projet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WorldIMaker.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WorldIMaker.dir/src/main.cpp.o -c /home/margaux/Documents/S3_OPENGL_Projet/src/main.cpp

CMakeFiles/WorldIMaker.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WorldIMaker.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/margaux/Documents/S3_OPENGL_Projet/src/main.cpp > CMakeFiles/WorldIMaker.dir/src/main.cpp.i

CMakeFiles/WorldIMaker.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WorldIMaker.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/margaux/Documents/S3_OPENGL_Projet/src/main.cpp -o CMakeFiles/WorldIMaker.dir/src/main.cpp.s

# Object files for target WorldIMaker
WorldIMaker_OBJECTS = \
"CMakeFiles/WorldIMaker.dir/src/cube.cpp.o" \
"CMakeFiles/WorldIMaker.dir/src/main.cpp.o"

# External object files for target WorldIMaker
WorldIMaker_EXTERNAL_OBJECTS =

bin/WorldIMaker: CMakeFiles/WorldIMaker.dir/src/cube.cpp.o
bin/WorldIMaker: CMakeFiles/WorldIMaker.dir/src/main.cpp.o
bin/WorldIMaker: CMakeFiles/WorldIMaker.dir/build.make
bin/WorldIMaker: lib/libglimac.a
bin/WorldIMaker: /usr/lib/x86_64-linux-gnu/libSDLmain.a
bin/WorldIMaker: /usr/lib/x86_64-linux-gnu/libSDL.so
bin/WorldIMaker: /usr/lib/x86_64-linux-gnu/libGL.so
bin/WorldIMaker: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/WorldIMaker: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/WorldIMaker: CMakeFiles/WorldIMaker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/margaux/Documents/S3_OPENGL_Projet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/WorldIMaker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WorldIMaker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WorldIMaker.dir/build: bin/WorldIMaker

.PHONY : CMakeFiles/WorldIMaker.dir/build

CMakeFiles/WorldIMaker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WorldIMaker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WorldIMaker.dir/clean

CMakeFiles/WorldIMaker.dir/depend:
	cd /home/margaux/Documents/S3_OPENGL_Projet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/margaux/Documents/S3_OPENGL_Projet /home/margaux/Documents/S3_OPENGL_Projet /home/margaux/Documents/S3_OPENGL_Projet /home/margaux/Documents/S3_OPENGL_Projet /home/margaux/Documents/S3_OPENGL_Projet/CMakeFiles/WorldIMaker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WorldIMaker.dir/depend

