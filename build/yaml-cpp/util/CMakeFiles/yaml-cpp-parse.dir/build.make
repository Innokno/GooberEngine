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

# Include any dependencies generated for this target.
include yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/compiler_depend.make

# Include the progress variables for this target.
include yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/progress.make

# Include the compile flags for this target's objects.
include yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/flags.make

yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/codegen:
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/codegen

yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o: yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/flags.make
yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o: /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/yaml-cpp/util/parse.cpp
yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o: yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o"
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o -MF CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o.d -o CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o -c /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/yaml-cpp/util/parse.cpp

yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/yaml-cpp-parse.dir/parse.cpp.i"
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/yaml-cpp/util/parse.cpp > CMakeFiles/yaml-cpp-parse.dir/parse.cpp.i

yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/yaml-cpp-parse.dir/parse.cpp.s"
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/yaml-cpp/util/parse.cpp -o CMakeFiles/yaml-cpp-parse.dir/parse.cpp.s

# Object files for target yaml-cpp-parse
yaml__cpp__parse_OBJECTS = \
"CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o"

# External object files for target yaml-cpp-parse
yaml__cpp__parse_EXTERNAL_OBJECTS =

yaml-cpp/util/parse: yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/parse.cpp.o
yaml-cpp/util/parse: yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/build.make
yaml-cpp/util/parse: yaml-cpp/libyaml-cpp.a
yaml-cpp/util/parse: yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable parse"
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yaml-cpp-parse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/build: yaml-cpp/util/parse
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/build

yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/clean:
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util && $(CMAKE_COMMAND) -P CMakeFiles/yaml-cpp-parse.dir/cmake_clean.cmake
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/clean

yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/depend:
	cd /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/yaml-cpp/util /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util /Users/nikolaiovereem/Documents/Code/RayCastingEngine/CPPVer/build/yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : yaml-cpp/util/CMakeFiles/yaml-cpp-parse.dir/depend

