# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mathewjacob/dev/cppprojects/HuffmanTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mathewjacob/dev/cppprojects/HuffmanTree/build

# Include any dependencies generated for this target.
include CMakeFiles/test_priority.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_priority.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_priority.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_priority.dir/flags.make

CMakeFiles/test_priority.dir/src/test_priority.cpp.o: CMakeFiles/test_priority.dir/flags.make
CMakeFiles/test_priority.dir/src/test_priority.cpp.o: ../src/test_priority.cpp
CMakeFiles/test_priority.dir/src/test_priority.cpp.o: CMakeFiles/test_priority.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mathewjacob/dev/cppprojects/HuffmanTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_priority.dir/src/test_priority.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_priority.dir/src/test_priority.cpp.o -MF CMakeFiles/test_priority.dir/src/test_priority.cpp.o.d -o CMakeFiles/test_priority.dir/src/test_priority.cpp.o -c /Users/mathewjacob/dev/cppprojects/HuffmanTree/src/test_priority.cpp

CMakeFiles/test_priority.dir/src/test_priority.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_priority.dir/src/test_priority.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mathewjacob/dev/cppprojects/HuffmanTree/src/test_priority.cpp > CMakeFiles/test_priority.dir/src/test_priority.cpp.i

CMakeFiles/test_priority.dir/src/test_priority.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_priority.dir/src/test_priority.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mathewjacob/dev/cppprojects/HuffmanTree/src/test_priority.cpp -o CMakeFiles/test_priority.dir/src/test_priority.cpp.s

# Object files for target test_priority
test_priority_OBJECTS = \
"CMakeFiles/test_priority.dir/src/test_priority.cpp.o"

# External object files for target test_priority
test_priority_EXTERNAL_OBJECTS =

bin/test_priority: CMakeFiles/test_priority.dir/src/test_priority.cpp.o
bin/test_priority: CMakeFiles/test_priority.dir/build.make
bin/test_priority: CMakeFiles/test_priority.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mathewjacob/dev/cppprojects/HuffmanTree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/test_priority"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_priority.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_priority.dir/build: bin/test_priority
.PHONY : CMakeFiles/test_priority.dir/build

CMakeFiles/test_priority.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_priority.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_priority.dir/clean

CMakeFiles/test_priority.dir/depend:
	cd /Users/mathewjacob/dev/cppprojects/HuffmanTree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mathewjacob/dev/cppprojects/HuffmanTree /Users/mathewjacob/dev/cppprojects/HuffmanTree /Users/mathewjacob/dev/cppprojects/HuffmanTree/build /Users/mathewjacob/dev/cppprojects/HuffmanTree/build /Users/mathewjacob/dev/cppprojects/HuffmanTree/build/CMakeFiles/test_priority.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_priority.dir/depend
