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
CMAKE_SOURCE_DIR = "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/S3_OPENGL_Projet"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/S3_OPENGL_Projet"

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
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/S3_OPENGL_Projet/CMakeFiles" "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/S3_OPENGL_Projet/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/laurelenn/Dropbox/Importants/IMAC/A2/S3 - OpenGL/S3_OPENGL_Projet/CMakeFiles" 0
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
# Target rules for targets named WorldIMaker

# Build rule for target.
WorldIMaker: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 WorldIMaker
.PHONY : WorldIMaker

# fast build rule for target.
WorldIMaker/fast:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/build
.PHONY : WorldIMaker/fast

#=============================================================================
# Target rules for targets named glimac

# Build rule for target.
glimac: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glimac
.PHONY : glimac

# fast build rule for target.
glimac/fast:
	$(MAKE) -f lib/glimac/CMakeFiles/glimac.dir/build.make lib/glimac/CMakeFiles/glimac.dir/build
.PHONY : glimac/fast

src/FreeflyCamera.o: src/FreeflyCamera.cpp.o

.PHONY : src/FreeflyCamera.o

# target to build an object file
src/FreeflyCamera.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/FreeflyCamera.cpp.o
.PHONY : src/FreeflyCamera.cpp.o

src/FreeflyCamera.i: src/FreeflyCamera.cpp.i

.PHONY : src/FreeflyCamera.i

# target to preprocess a source file
src/FreeflyCamera.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/FreeflyCamera.cpp.i
.PHONY : src/FreeflyCamera.cpp.i

src/FreeflyCamera.s: src/FreeflyCamera.cpp.s

.PHONY : src/FreeflyCamera.s

# target to generate assembly for a file
src/FreeflyCamera.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/FreeflyCamera.cpp.s
.PHONY : src/FreeflyCamera.cpp.s

src/cube.o: src/cube.cpp.o

.PHONY : src/cube.o

# target to build an object file
src/cube.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/cube.cpp.o
.PHONY : src/cube.cpp.o

src/cube.i: src/cube.cpp.i

.PHONY : src/cube.i

# target to preprocess a source file
src/cube.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/cube.cpp.i
.PHONY : src/cube.cpp.i

src/cube.s: src/cube.cpp.s

.PHONY : src/cube.s

# target to generate assembly for a file
src/cube.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/cube.cpp.s
.PHONY : src/cube.cpp.s

src/display.o: src/display.cpp.o

.PHONY : src/display.o

# target to build an object file
src/display.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/display.cpp.o
.PHONY : src/display.cpp.o

src/display.i: src/display.cpp.i

.PHONY : src/display.i

# target to preprocess a source file
src/display.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/display.cpp.i
.PHONY : src/display.cpp.i

src/display.s: src/display.cpp.s

.PHONY : src/display.s

# target to generate assembly for a file
src/display.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/display.cpp.s
.PHONY : src/display.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/menu.o: src/menu.cpp.o

.PHONY : src/menu.o

# target to build an object file
src/menu.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/menu.cpp.o
.PHONY : src/menu.cpp.o

src/menu.i: src/menu.cpp.i

.PHONY : src/menu.i

# target to preprocess a source file
src/menu.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/menu.cpp.i
.PHONY : src/menu.cpp.i

src/menu.s: src/menu.cpp.s

.PHONY : src/menu.s

# target to generate assembly for a file
src/menu.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/menu.cpp.s
.PHONY : src/menu.cpp.s

src/myshader.o: src/myshader.cpp.o

.PHONY : src/myshader.o

# target to build an object file
src/myshader.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/myshader.cpp.o
.PHONY : src/myshader.cpp.o

src/myshader.i: src/myshader.cpp.i

.PHONY : src/myshader.i

# target to preprocess a source file
src/myshader.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/myshader.cpp.i
.PHONY : src/myshader.cpp.i

src/myshader.s: src/myshader.cpp.s

.PHONY : src/myshader.s

# target to generate assembly for a file
src/myshader.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/myshader.cpp.s
.PHONY : src/myshader.cpp.s

src/pinceau.o: src/pinceau.cpp.o

.PHONY : src/pinceau.o

# target to build an object file
src/pinceau.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/pinceau.cpp.o
.PHONY : src/pinceau.cpp.o

src/pinceau.i: src/pinceau.cpp.i

.PHONY : src/pinceau.i

# target to preprocess a source file
src/pinceau.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/pinceau.cpp.i
.PHONY : src/pinceau.cpp.i

src/pinceau.s: src/pinceau.cpp.s

.PHONY : src/pinceau.s

# target to generate assembly for a file
src/pinceau.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/pinceau.cpp.s
.PHONY : src/pinceau.cpp.s

src/radialBasisFunctions.o: src/radialBasisFunctions.cpp.o

.PHONY : src/radialBasisFunctions.o

# target to build an object file
src/radialBasisFunctions.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/radialBasisFunctions.cpp.o
.PHONY : src/radialBasisFunctions.cpp.o

src/radialBasisFunctions.i: src/radialBasisFunctions.cpp.i

.PHONY : src/radialBasisFunctions.i

# target to preprocess a source file
src/radialBasisFunctions.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/radialBasisFunctions.cpp.i
.PHONY : src/radialBasisFunctions.cpp.i

src/radialBasisFunctions.s: src/radialBasisFunctions.cpp.s

.PHONY : src/radialBasisFunctions.s

# target to generate assembly for a file
src/radialBasisFunctions.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/radialBasisFunctions.cpp.s
.PHONY : src/radialBasisFunctions.cpp.s

src/selector.o: src/selector.cpp.o

.PHONY : src/selector.o

# target to build an object file
src/selector.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/selector.cpp.o
.PHONY : src/selector.cpp.o

src/selector.i: src/selector.cpp.i

.PHONY : src/selector.i

# target to preprocess a source file
src/selector.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/selector.cpp.i
.PHONY : src/selector.cpp.i

src/selector.s: src/selector.cpp.s

.PHONY : src/selector.s

# target to generate assembly for a file
src/selector.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/selector.cpp.s
.PHONY : src/selector.cpp.s

src/skybox.o: src/skybox.cpp.o

.PHONY : src/skybox.o

# target to build an object file
src/skybox.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/skybox.cpp.o
.PHONY : src/skybox.cpp.o

src/skybox.i: src/skybox.cpp.i

.PHONY : src/skybox.i

# target to preprocess a source file
src/skybox.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/skybox.cpp.i
.PHONY : src/skybox.cpp.i

src/skybox.s: src/skybox.cpp.s

.PHONY : src/skybox.s

# target to generate assembly for a file
src/skybox.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/skybox.cpp.s
.PHONY : src/skybox.cpp.s

src/texture.o: src/texture.cpp.o

.PHONY : src/texture.o

# target to build an object file
src/texture.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/texture.cpp.o
.PHONY : src/texture.cpp.o

src/texture.i: src/texture.cpp.i

.PHONY : src/texture.i

# target to preprocess a source file
src/texture.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/texture.cpp.i
.PHONY : src/texture.cpp.i

src/texture.s: src/texture.cpp.s

.PHONY : src/texture.s

# target to generate assembly for a file
src/texture.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/texture.cpp.s
.PHONY : src/texture.cpp.s

src/vertex.o: src/vertex.cpp.o

.PHONY : src/vertex.o

# target to build an object file
src/vertex.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/vertex.cpp.o
.PHONY : src/vertex.cpp.o

src/vertex.i: src/vertex.cpp.i

.PHONY : src/vertex.i

# target to preprocess a source file
src/vertex.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/vertex.cpp.i
.PHONY : src/vertex.cpp.i

src/vertex.s: src/vertex.cpp.s

.PHONY : src/vertex.s

# target to generate assembly for a file
src/vertex.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/vertex.cpp.s
.PHONY : src/vertex.cpp.s

src/world.o: src/world.cpp.o

.PHONY : src/world.o

# target to build an object file
src/world.cpp.o:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/world.cpp.o
.PHONY : src/world.cpp.o

src/world.i: src/world.cpp.i

.PHONY : src/world.i

# target to preprocess a source file
src/world.cpp.i:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/world.cpp.i
.PHONY : src/world.cpp.i

src/world.s: src/world.cpp.s

.PHONY : src/world.s

# target to generate assembly for a file
src/world.cpp.s:
	$(MAKE) -f CMakeFiles/WorldIMaker.dir/build.make CMakeFiles/WorldIMaker.dir/src/world.cpp.s
.PHONY : src/world.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... WorldIMaker"
	@echo "... edit_cache"
	@echo "... glimac"
	@echo "... src/FreeflyCamera.o"
	@echo "... src/FreeflyCamera.i"
	@echo "... src/FreeflyCamera.s"
	@echo "... src/cube.o"
	@echo "... src/cube.i"
	@echo "... src/cube.s"
	@echo "... src/display.o"
	@echo "... src/display.i"
	@echo "... src/display.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/menu.o"
	@echo "... src/menu.i"
	@echo "... src/menu.s"
	@echo "... src/myshader.o"
	@echo "... src/myshader.i"
	@echo "... src/myshader.s"
	@echo "... src/pinceau.o"
	@echo "... src/pinceau.i"
	@echo "... src/pinceau.s"
	@echo "... src/radialBasisFunctions.o"
	@echo "... src/radialBasisFunctions.i"
	@echo "... src/radialBasisFunctions.s"
	@echo "... src/selector.o"
	@echo "... src/selector.i"
	@echo "... src/selector.s"
	@echo "... src/skybox.o"
	@echo "... src/skybox.i"
	@echo "... src/skybox.s"
	@echo "... src/texture.o"
	@echo "... src/texture.i"
	@echo "... src/texture.s"
	@echo "... src/vertex.o"
	@echo "... src/vertex.i"
	@echo "... src/vertex.s"
	@echo "... src/world.o"
	@echo "... src/world.i"
	@echo "... src/world.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

