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
include CMakeFiles/tl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tl.dir/flags.make

CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.o: CMakeFiles/tl.dir/flags.make
CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.o: ../contests/hashcode2020/tl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leo/code/oi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.o -c /Users/leo/code/oi/contests/hashcode2020/tl.cpp

CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leo/code/oi/contests/hashcode2020/tl.cpp > CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.i

CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leo/code/oi/contests/hashcode2020/tl.cpp -o CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.s

# Object files for target tl
tl_OBJECTS = \
"CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.o"

# External object files for target tl
tl_EXTERNAL_OBJECTS =

tl: CMakeFiles/tl.dir/contests/hashcode2020/tl.cpp.o
tl: CMakeFiles/tl.dir/build.make
tl: CMakeFiles/tl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leo/code/oi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tl.dir/build: tl

.PHONY : CMakeFiles/tl.dir/build

CMakeFiles/tl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tl.dir/clean

CMakeFiles/tl.dir/depend:
	cd /Users/leo/code/oi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leo/code/oi /Users/leo/code/oi /Users/leo/code/oi/cmake-build-debug /Users/leo/code/oi/cmake-build-debug /Users/leo/code/oi/cmake-build-debug/CMakeFiles/tl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tl.dir/depend

