# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\c_projects\getriebe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\c_projects\getriebe

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start D:\c_projects\getriebe\CMakeFiles D:\c_projects\getriebe\\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start D:\c_projects\getriebe\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -P D:\c_projects\getriebe\CMakeFiles\VerifyGlobs.cmake
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named getriebe

# Build rule for target.
getriebe: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 getriebe
.PHONY : getriebe

# fast build rule for target.
getriebe/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/build
.PHONY : getriebe/fast

src/getriebe.obj: src/getriebe.c.obj
.PHONY : src/getriebe.obj

# target to build an object file
src/getriebe.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/getriebe.c.obj
.PHONY : src/getriebe.c.obj

src/getriebe.i: src/getriebe.c.i
.PHONY : src/getriebe.i

# target to preprocess a source file
src/getriebe.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/getriebe.c.i
.PHONY : src/getriebe.c.i

src/getriebe.s: src/getriebe.c.s
.PHONY : src/getriebe.s

# target to generate assembly for a file
src/getriebe.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/getriebe.c.s
.PHONY : src/getriebe.c.s

src/main.obj: src/main.c.obj
.PHONY : src/main.obj

# target to build an object file
src/main.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/main.c.obj
.PHONY : src/main.c.obj

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/main.c.s
.PHONY : src/main.c.s

src/opcode/opcode_control.obj: src/opcode/opcode_control.c.obj
.PHONY : src/opcode/opcode_control.obj

# target to build an object file
src/opcode/opcode_control.c.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/opcode/opcode_control.c.obj
.PHONY : src/opcode/opcode_control.c.obj

src/opcode/opcode_control.i: src/opcode/opcode_control.c.i
.PHONY : src/opcode/opcode_control.i

# target to preprocess a source file
src/opcode/opcode_control.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/opcode/opcode_control.c.i
.PHONY : src/opcode/opcode_control.c.i

src/opcode/opcode_control.s: src/opcode/opcode_control.c.s
.PHONY : src/opcode/opcode_control.s

# target to generate assembly for a file
src/opcode/opcode_control.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\getriebe.dir\build.make CMakeFiles/getriebe.dir/src/opcode/opcode_control.c.s
.PHONY : src/opcode/opcode_control.c.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... getriebe
	@echo ... src/getriebe.obj
	@echo ... src/getriebe.i
	@echo ... src/getriebe.s
	@echo ... src/main.obj
	@echo ... src/main.i
	@echo ... src/main.s
	@echo ... src/opcode/opcode_control.obj
	@echo ... src/opcode/opcode_control.i
	@echo ... src/opcode/opcode_control.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -P D:\c_projects\getriebe\CMakeFiles\VerifyGlobs.cmake
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

