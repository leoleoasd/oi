# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/Users/leo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/leo/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6397.106/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leo/code/oi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leo/code/oi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linerly.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linerly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linerly.dir/flags.make

CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.o: CMakeFiles/linerly.dir/flags.make
CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.o: ../contests/2020ieee/linerly.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leo/code/oi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.o -c /Users/leo/code/oi/contests/2020ieee/linerly.cpp

CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leo/code/oi/contests/2020ieee/linerly.cpp > CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.i

CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leo/code/oi/contests/2020ieee/linerly.cpp -o CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.s

# Object files for target linerly
linerly_OBJECTS = \
"CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.o"

# External object files for target linerly
linerly_EXTERNAL_OBJECTS =

linerly: CMakeFiles/linerly.dir/contests/2020ieee/linerly.cpp.o
linerly: CMakeFiles/linerly.dir/build.make
linerly: CMakeFiles/linerly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leo/code/oi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linerly"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linerly.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linerly.dir/build: linerly

.PHONY : CMakeFiles/linerly.dir/build

CMakeFiles/linerly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linerly.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linerly.dir/clean

CMakeFiles/linerly.dir/depend:
	cd /Users/leo/code/oi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leo/code/oi /Users/leo/code/oi /Users/leo/code/oi/cmake-build-debug /Users/leo/code/oi/cmake-build-debug /Users/leo/code/oi/cmake-build-debug/CMakeFiles/linerly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linerly.dir/depend

