# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/Users/leo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/leo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leo/code/oi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leo/code/oi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/random.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/random.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/random.dir/flags.make

CMakeFiles/random.dir/contests/hashcode2020/random.cpp.o: CMakeFiles/random.dir/flags.make
CMakeFiles/random.dir/contests/hashcode2020/random.cpp.o: ../contests/hashcode2020/random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leo/code/oi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/random.dir/contests/hashcode2020/random.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/random.dir/contests/hashcode2020/random.cpp.o -c /Users/leo/code/oi/contests/hashcode2020/random.cpp

CMakeFiles/random.dir/contests/hashcode2020/random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/random.dir/contests/hashcode2020/random.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leo/code/oi/contests/hashcode2020/random.cpp > CMakeFiles/random.dir/contests/hashcode2020/random.cpp.i

CMakeFiles/random.dir/contests/hashcode2020/random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/random.dir/contests/hashcode2020/random.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leo/code/oi/contests/hashcode2020/random.cpp -o CMakeFiles/random.dir/contests/hashcode2020/random.cpp.s

# Object files for target random
random_OBJECTS = \
"CMakeFiles/random.dir/contests/hashcode2020/random.cpp.o"

# External object files for target random
random_EXTERNAL_OBJECTS =

random: CMakeFiles/random.dir/contests/hashcode2020/random.cpp.o
random: CMakeFiles/random.dir/build.make
random: CMakeFiles/random.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leo/code/oi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable random"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/random.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/random.dir/build: random

.PHONY : CMakeFiles/random.dir/build

CMakeFiles/random.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/random.dir/cmake_clean.cmake
.PHONY : CMakeFiles/random.dir/clean

CMakeFiles/random.dir/depend:
	cd /Users/leo/code/oi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leo/code/oi /Users/leo/code/oi /Users/leo/code/oi/cmake-build-debug /Users/leo/code/oi/cmake-build-debug /Users/leo/code/oi/cmake-build-debug/CMakeFiles/random.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/random.dir/depend
