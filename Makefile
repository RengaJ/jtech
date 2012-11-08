# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/RengaJ/Documents/jtech

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/RengaJ/Documents/jtech

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip
.PHONY : install/strip/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/RengaJ/Documents/jtech/CMakeFiles /home/RengaJ/Documents/jtech/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/RengaJ/Documents/jtech/CMakeFiles 0
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
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named jtech.out

# Build rule for target.
jtech.out: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 jtech.out
.PHONY : jtech.out

# fast build rule for target.
jtech.out/fast:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/build
.PHONY : jtech.out/fast

src/jdebug.o: src/jdebug.cpp.o
.PHONY : src/jdebug.o

# target to build an object file
src/jdebug.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/jdebug.cpp.o
.PHONY : src/jdebug.cpp.o

src/jdebug.i: src/jdebug.cpp.i
.PHONY : src/jdebug.i

# target to preprocess a source file
src/jdebug.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/jdebug.cpp.i
.PHONY : src/jdebug.cpp.i

src/jdebug.s: src/jdebug.cpp.s
.PHONY : src/jdebug.s

# target to generate assembly for a file
src/jdebug.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/jdebug.cpp.s
.PHONY : src/jdebug.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/math/matrix/jmatrix2x2.o: src/math/matrix/jmatrix2x2.cpp.o
.PHONY : src/math/matrix/jmatrix2x2.o

# target to build an object file
src/math/matrix/jmatrix2x2.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix2x2.cpp.o
.PHONY : src/math/matrix/jmatrix2x2.cpp.o

src/math/matrix/jmatrix2x2.i: src/math/matrix/jmatrix2x2.cpp.i
.PHONY : src/math/matrix/jmatrix2x2.i

# target to preprocess a source file
src/math/matrix/jmatrix2x2.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix2x2.cpp.i
.PHONY : src/math/matrix/jmatrix2x2.cpp.i

src/math/matrix/jmatrix2x2.s: src/math/matrix/jmatrix2x2.cpp.s
.PHONY : src/math/matrix/jmatrix2x2.s

# target to generate assembly for a file
src/math/matrix/jmatrix2x2.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix2x2.cpp.s
.PHONY : src/math/matrix/jmatrix2x2.cpp.s

src/math/matrix/jmatrix3x3.o: src/math/matrix/jmatrix3x3.cpp.o
.PHONY : src/math/matrix/jmatrix3x3.o

# target to build an object file
src/math/matrix/jmatrix3x3.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix3x3.cpp.o
.PHONY : src/math/matrix/jmatrix3x3.cpp.o

src/math/matrix/jmatrix3x3.i: src/math/matrix/jmatrix3x3.cpp.i
.PHONY : src/math/matrix/jmatrix3x3.i

# target to preprocess a source file
src/math/matrix/jmatrix3x3.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix3x3.cpp.i
.PHONY : src/math/matrix/jmatrix3x3.cpp.i

src/math/matrix/jmatrix3x3.s: src/math/matrix/jmatrix3x3.cpp.s
.PHONY : src/math/matrix/jmatrix3x3.s

# target to generate assembly for a file
src/math/matrix/jmatrix3x3.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix3x3.cpp.s
.PHONY : src/math/matrix/jmatrix3x3.cpp.s

src/math/matrix/jmatrix4x4.o: src/math/matrix/jmatrix4x4.cpp.o
.PHONY : src/math/matrix/jmatrix4x4.o

# target to build an object file
src/math/matrix/jmatrix4x4.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix4x4.cpp.o
.PHONY : src/math/matrix/jmatrix4x4.cpp.o

src/math/matrix/jmatrix4x4.i: src/math/matrix/jmatrix4x4.cpp.i
.PHONY : src/math/matrix/jmatrix4x4.i

# target to preprocess a source file
src/math/matrix/jmatrix4x4.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix4x4.cpp.i
.PHONY : src/math/matrix/jmatrix4x4.cpp.i

src/math/matrix/jmatrix4x4.s: src/math/matrix/jmatrix4x4.cpp.s
.PHONY : src/math/matrix/jmatrix4x4.s

# target to generate assembly for a file
src/math/matrix/jmatrix4x4.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/matrix/jmatrix4x4.cpp.s
.PHONY : src/math/matrix/jmatrix4x4.cpp.s

src/math/vector/jvector2.o: src/math/vector/jvector2.cpp.o
.PHONY : src/math/vector/jvector2.o

# target to build an object file
src/math/vector/jvector2.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector2.cpp.o
.PHONY : src/math/vector/jvector2.cpp.o

src/math/vector/jvector2.i: src/math/vector/jvector2.cpp.i
.PHONY : src/math/vector/jvector2.i

# target to preprocess a source file
src/math/vector/jvector2.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector2.cpp.i
.PHONY : src/math/vector/jvector2.cpp.i

src/math/vector/jvector2.s: src/math/vector/jvector2.cpp.s
.PHONY : src/math/vector/jvector2.s

# target to generate assembly for a file
src/math/vector/jvector2.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector2.cpp.s
.PHONY : src/math/vector/jvector2.cpp.s

src/math/vector/jvector3.o: src/math/vector/jvector3.cpp.o
.PHONY : src/math/vector/jvector3.o

# target to build an object file
src/math/vector/jvector3.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector3.cpp.o
.PHONY : src/math/vector/jvector3.cpp.o

src/math/vector/jvector3.i: src/math/vector/jvector3.cpp.i
.PHONY : src/math/vector/jvector3.i

# target to preprocess a source file
src/math/vector/jvector3.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector3.cpp.i
.PHONY : src/math/vector/jvector3.cpp.i

src/math/vector/jvector3.s: src/math/vector/jvector3.cpp.s
.PHONY : src/math/vector/jvector3.s

# target to generate assembly for a file
src/math/vector/jvector3.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector3.cpp.s
.PHONY : src/math/vector/jvector3.cpp.s

src/math/vector/jvector4.o: src/math/vector/jvector4.cpp.o
.PHONY : src/math/vector/jvector4.o

# target to build an object file
src/math/vector/jvector4.cpp.o:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector4.cpp.o
.PHONY : src/math/vector/jvector4.cpp.o

src/math/vector/jvector4.i: src/math/vector/jvector4.cpp.i
.PHONY : src/math/vector/jvector4.i

# target to preprocess a source file
src/math/vector/jvector4.cpp.i:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector4.cpp.i
.PHONY : src/math/vector/jvector4.cpp.i

src/math/vector/jvector4.s: src/math/vector/jvector4.cpp.s
.PHONY : src/math/vector/jvector4.s

# target to generate assembly for a file
src/math/vector/jvector4.cpp.s:
	$(MAKE) -f CMakeFiles/jtech.out.dir/build.make CMakeFiles/jtech.out.dir/src/math/vector/jvector4.cpp.s
.PHONY : src/math/vector/jvector4.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... jtech.out"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... src/jdebug.o"
	@echo "... src/jdebug.i"
	@echo "... src/jdebug.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/math/matrix/jmatrix2x2.o"
	@echo "... src/math/matrix/jmatrix2x2.i"
	@echo "... src/math/matrix/jmatrix2x2.s"
	@echo "... src/math/matrix/jmatrix3x3.o"
	@echo "... src/math/matrix/jmatrix3x3.i"
	@echo "... src/math/matrix/jmatrix3x3.s"
	@echo "... src/math/matrix/jmatrix4x4.o"
	@echo "... src/math/matrix/jmatrix4x4.i"
	@echo "... src/math/matrix/jmatrix4x4.s"
	@echo "... src/math/vector/jvector2.o"
	@echo "... src/math/vector/jvector2.i"
	@echo "... src/math/vector/jvector2.s"
	@echo "... src/math/vector/jvector3.o"
	@echo "... src/math/vector/jvector3.i"
	@echo "... src/math/vector/jvector3.s"
	@echo "... src/math/vector/jvector4.o"
	@echo "... src/math/vector/jvector4.i"
	@echo "... src/math/vector/jvector4.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

