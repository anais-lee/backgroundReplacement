# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/AngelaLee/Documents/senior design/test-opencv"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/AngelaLee/Documents/senior design/test-opencv"

# Include any dependencies generated for this target.
include CMakeFiles/kmeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kmeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kmeans.dir/flags.make

CMakeFiles/kmeans.dir/kmeans.cpp.o: CMakeFiles/kmeans.dir/flags.make
CMakeFiles/kmeans.dir/kmeans.cpp.o: kmeans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/AngelaLee/Documents/senior design/test-opencv/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kmeans.dir/kmeans.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kmeans.dir/kmeans.cpp.o -c "/Users/AngelaLee/Documents/senior design/test-opencv/kmeans.cpp"

CMakeFiles/kmeans.dir/kmeans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kmeans.dir/kmeans.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/AngelaLee/Documents/senior design/test-opencv/kmeans.cpp" > CMakeFiles/kmeans.dir/kmeans.cpp.i

CMakeFiles/kmeans.dir/kmeans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kmeans.dir/kmeans.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/AngelaLee/Documents/senior design/test-opencv/kmeans.cpp" -o CMakeFiles/kmeans.dir/kmeans.cpp.s

CMakeFiles/kmeans.dir/kmeans.cpp.o.requires:

.PHONY : CMakeFiles/kmeans.dir/kmeans.cpp.o.requires

CMakeFiles/kmeans.dir/kmeans.cpp.o.provides: CMakeFiles/kmeans.dir/kmeans.cpp.o.requires
	$(MAKE) -f CMakeFiles/kmeans.dir/build.make CMakeFiles/kmeans.dir/kmeans.cpp.o.provides.build
.PHONY : CMakeFiles/kmeans.dir/kmeans.cpp.o.provides

CMakeFiles/kmeans.dir/kmeans.cpp.o.provides.build: CMakeFiles/kmeans.dir/kmeans.cpp.o


# Object files for target kmeans
kmeans_OBJECTS = \
"CMakeFiles/kmeans.dir/kmeans.cpp.o"

# External object files for target kmeans
kmeans_EXTERNAL_OBJECTS =

kmeans: CMakeFiles/kmeans.dir/kmeans.cpp.o
kmeans: CMakeFiles/kmeans.dir/build.make
kmeans: CMakeFiles/kmeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/AngelaLee/Documents/senior design/test-opencv/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kmeans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kmeans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kmeans.dir/build: kmeans

.PHONY : CMakeFiles/kmeans.dir/build

CMakeFiles/kmeans.dir/requires: CMakeFiles/kmeans.dir/kmeans.cpp.o.requires

.PHONY : CMakeFiles/kmeans.dir/requires

CMakeFiles/kmeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kmeans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kmeans.dir/clean

CMakeFiles/kmeans.dir/depend:
	cd "/Users/AngelaLee/Documents/senior design/test-opencv" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv/CMakeFiles/kmeans.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/kmeans.dir/depend
