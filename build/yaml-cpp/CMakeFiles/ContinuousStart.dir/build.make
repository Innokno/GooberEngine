# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build

# Utility rule file for ContinuousStart.

# Include any custom commands dependencies for this target.
include yaml-cpp/CMakeFiles/ContinuousStart.dir/compiler_depend.make

# Include the progress variables for this target.
include yaml-cpp/CMakeFiles/ContinuousStart.dir/progress.make

yaml-cpp/CMakeFiles/ContinuousStart:
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp && /opt/homebrew/bin/ctest -D ContinuousStart

yaml-cpp/CMakeFiles/ContinuousStart.dir/codegen:
.PHONY : yaml-cpp/CMakeFiles/ContinuousStart.dir/codegen

ContinuousStart: yaml-cpp/CMakeFiles/ContinuousStart
ContinuousStart: yaml-cpp/CMakeFiles/ContinuousStart.dir/build.make
.PHONY : ContinuousStart

# Rule to build all files generated by this target.
yaml-cpp/CMakeFiles/ContinuousStart.dir/build: ContinuousStart
.PHONY : yaml-cpp/CMakeFiles/ContinuousStart.dir/build

yaml-cpp/CMakeFiles/ContinuousStart.dir/clean:
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousStart.dir/cmake_clean.cmake
.PHONY : yaml-cpp/CMakeFiles/ContinuousStart.dir/clean

yaml-cpp/CMakeFiles/ContinuousStart.dir/depend:
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/yaml-cpp /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/CMakeFiles/ContinuousStart.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : yaml-cpp/CMakeFiles/ContinuousStart.dir/depend

