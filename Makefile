# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/OPENGL_Project_S3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/OPENGL_Project_S3"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/OPENGL_Project_S3/CMakeFiles" "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/OPENGL_Project_S3/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/OPENGL_Project_S3/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named GLAD

# Build rule for target.
GLAD: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 GLAD
.PHONY : GLAD

# fast build rule for target.
GLAD/fast:
	$(MAKE) -f CMakeFiles/GLAD.dir/build.make CMakeFiles/GLAD.dir/build
.PHONY : GLAD/fast

#=============================================================================
# Target rules for targets named opengl-tutorials

# Build rule for target.
opengl-tutorials: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 opengl-tutorials
.PHONY : opengl-tutorials

# fast build rule for target.
opengl-tutorials/fast:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/build
.PHONY : opengl-tutorials/fast

lib/glad/src/glad.o: lib/glad/src/glad.c.o

.PHONY : lib/glad/src/glad.o

# target to build an object file
lib/glad/src/glad.c.o:
	$(MAKE) -f CMakeFiles/GLAD.dir/build.make CMakeFiles/GLAD.dir/lib/glad/src/glad.c.o
.PHONY : lib/glad/src/glad.c.o

lib/glad/src/glad.i: lib/glad/src/glad.c.i

.PHONY : lib/glad/src/glad.i

# target to preprocess a source file
lib/glad/src/glad.c.i:
	$(MAKE) -f CMakeFiles/GLAD.dir/build.make CMakeFiles/GLAD.dir/lib/glad/src/glad.c.i
.PHONY : lib/glad/src/glad.c.i

lib/glad/src/glad.s: lib/glad/src/glad.c.s

.PHONY : lib/glad/src/glad.s

# target to generate assembly for a file
lib/glad/src/glad.c.s:
	$(MAKE) -f CMakeFiles/GLAD.dir/build.make CMakeFiles/GLAD.dir/lib/glad/src/glad.c.s
.PHONY : lib/glad/src/glad.c.s

src/FreeflyCamera.o: src/FreeflyCamera.cpp.o

.PHONY : src/FreeflyCamera.o

# target to build an object file
src/FreeflyCamera.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/FreeflyCamera.cpp.o
.PHONY : src/FreeflyCamera.cpp.o

src/FreeflyCamera.i: src/FreeflyCamera.cpp.i

.PHONY : src/FreeflyCamera.i

# target to preprocess a source file
src/FreeflyCamera.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/FreeflyCamera.cpp.i
.PHONY : src/FreeflyCamera.cpp.i

src/FreeflyCamera.s: src/FreeflyCamera.cpp.s

.PHONY : src/FreeflyCamera.s

# target to generate assembly for a file
src/FreeflyCamera.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/FreeflyCamera.cpp.s
.PHONY : src/FreeflyCamera.cpp.s

src/app.o: src/app.cpp.o

.PHONY : src/app.o

# target to build an object file
src/app.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/app.cpp.o
.PHONY : src/app.cpp.o

src/app.i: src/app.cpp.i

.PHONY : src/app.i

# target to preprocess a source file
src/app.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/app.cpp.i
.PHONY : src/app.cpp.i

src/app.s: src/app.cpp.s

.PHONY : src/app.s

# target to generate assembly for a file
src/app.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/app.cpp.s
.PHONY : src/app.cpp.s

src/camera.o: src/camera.cpp.o

.PHONY : src/camera.o

# target to build an object file
src/camera.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/camera.cpp.o
.PHONY : src/camera.cpp.o

src/camera.i: src/camera.cpp.i

.PHONY : src/camera.i

# target to preprocess a source file
src/camera.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/camera.cpp.i
.PHONY : src/camera.cpp.i

src/camera.s: src/camera.cpp.s

.PHONY : src/camera.s

# target to generate assembly for a file
src/camera.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/camera.cpp.s
.PHONY : src/camera.cpp.s

src/cube.o: src/cube.cpp.o

.PHONY : src/cube.o

# target to build an object file
src/cube.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/cube.cpp.o
.PHONY : src/cube.cpp.o

src/cube.i: src/cube.cpp.i

.PHONY : src/cube.i

# target to preprocess a source file
src/cube.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/cube.cpp.i
.PHONY : src/cube.cpp.i

src/cube.s: src/cube.cpp.s

.PHONY : src/cube.s

# target to generate assembly for a file
src/cube.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/cube.cpp.s
.PHONY : src/cube.cpp.s

src/gl_exception.o: src/gl_exception.cpp.o

.PHONY : src/gl_exception.o

# target to build an object file
src/gl_exception.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/gl_exception.cpp.o
.PHONY : src/gl_exception.cpp.o

src/gl_exception.i: src/gl_exception.cpp.i

.PHONY : src/gl_exception.i

# target to preprocess a source file
src/gl_exception.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/gl_exception.cpp.i
.PHONY : src/gl_exception.cpp.i

src/gl_exception.s: src/gl_exception.cpp.s

.PHONY : src/gl_exception.s

# target to generate assembly for a file
src/gl_exception.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/gl_exception.cpp.s
.PHONY : src/gl_exception.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/object.o: src/object.cpp.o

.PHONY : src/object.o

# target to build an object file
src/object.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/object.cpp.o
.PHONY : src/object.cpp.o

src/object.i: src/object.cpp.i

.PHONY : src/object.i

# target to preprocess a source file
src/object.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/object.cpp.i
.PHONY : src/object.cpp.i

src/object.s: src/object.cpp.s

.PHONY : src/object.s

# target to generate assembly for a file
src/object.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/object.cpp.s
.PHONY : src/object.cpp.s

src/selector.o: src/selector.cpp.o

.PHONY : src/selector.o

# target to build an object file
src/selector.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/selector.cpp.o
.PHONY : src/selector.cpp.o

src/selector.i: src/selector.cpp.i

.PHONY : src/selector.i

# target to preprocess a source file
src/selector.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/selector.cpp.i
.PHONY : src/selector.cpp.i

src/selector.s: src/selector.cpp.s

.PHONY : src/selector.s

# target to generate assembly for a file
src/selector.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/selector.cpp.s
.PHONY : src/selector.cpp.s

src/shader.o: src/shader.cpp.o

.PHONY : src/shader.o

# target to build an object file
src/shader.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/shader.cpp.o
.PHONY : src/shader.cpp.o

src/shader.i: src/shader.cpp.i

.PHONY : src/shader.i

# target to preprocess a source file
src/shader.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/shader.cpp.i
.PHONY : src/shader.cpp.i

src/shader.s: src/shader.cpp.s

.PHONY : src/shader.s

# target to generate assembly for a file
src/shader.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/shader.cpp.s
.PHONY : src/shader.cpp.s

src/util.o: src/util.cpp.o

.PHONY : src/util.o

# target to build an object file
src/util.cpp.o:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/util.cpp.o
.PHONY : src/util.cpp.o

src/util.i: src/util.cpp.i

.PHONY : src/util.i

# target to preprocess a source file
src/util.cpp.i:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/util.cpp.i
.PHONY : src/util.cpp.i

src/util.s: src/util.cpp.s

.PHONY : src/util.s

# target to generate assembly for a file
src/util.cpp.s:
	$(MAKE) -f CMakeFiles/opengl-tutorials.dir/build.make CMakeFiles/opengl-tutorials.dir/src/util.cpp.s
.PHONY : src/util.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... GLAD"
	@echo "... edit_cache"
	@echo "... opengl-tutorials"
	@echo "... lib/glad/src/glad.o"
	@echo "... lib/glad/src/glad.i"
	@echo "... lib/glad/src/glad.s"
	@echo "... src/FreeflyCamera.o"
	@echo "... src/FreeflyCamera.i"
	@echo "... src/FreeflyCamera.s"
	@echo "... src/app.o"
	@echo "... src/app.i"
	@echo "... src/app.s"
	@echo "... src/camera.o"
	@echo "... src/camera.i"
	@echo "... src/camera.s"
	@echo "... src/cube.o"
	@echo "... src/cube.i"
	@echo "... src/cube.s"
	@echo "... src/gl_exception.o"
	@echo "... src/gl_exception.i"
	@echo "... src/gl_exception.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/object.o"
	@echo "... src/object.i"
	@echo "... src/object.s"
	@echo "... src/selector.o"
	@echo "... src/selector.i"
	@echo "... src/selector.s"
	@echo "... src/shader.o"
	@echo "... src/shader.i"
	@echo "... src/shader.s"
	@echo "... src/util.o"
	@echo "... src/util.i"
	@echo "... src/util.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

