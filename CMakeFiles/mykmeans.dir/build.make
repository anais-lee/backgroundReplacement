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
include CMakeFiles/mykmeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mykmeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mykmeans.dir/flags.make

CMakeFiles/mykmeans.dir/mykmeans.cpp.o: CMakeFiles/mykmeans.dir/flags.make
CMakeFiles/mykmeans.dir/mykmeans.cpp.o: mykmeans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/AngelaLee/Documents/senior design/test-opencv/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mykmeans.dir/mykmeans.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mykmeans.dir/mykmeans.cpp.o -c "/Users/AngelaLee/Documents/senior design/test-opencv/mykmeans.cpp"

CMakeFiles/mykmeans.dir/mykmeans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mykmeans.dir/mykmeans.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/AngelaLee/Documents/senior design/test-opencv/mykmeans.cpp" > CMakeFiles/mykmeans.dir/mykmeans.cpp.i

CMakeFiles/mykmeans.dir/mykmeans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mykmeans.dir/mykmeans.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/AngelaLee/Documents/senior design/test-opencv/mykmeans.cpp" -o CMakeFiles/mykmeans.dir/mykmeans.cpp.s

CMakeFiles/mykmeans.dir/mykmeans.cpp.o.requires:

.PHONY : CMakeFiles/mykmeans.dir/mykmeans.cpp.o.requires

CMakeFiles/mykmeans.dir/mykmeans.cpp.o.provides: CMakeFiles/mykmeans.dir/mykmeans.cpp.o.requires
	$(MAKE) -f CMakeFiles/mykmeans.dir/build.make CMakeFiles/mykmeans.dir/mykmeans.cpp.o.provides.build
.PHONY : CMakeFiles/mykmeans.dir/mykmeans.cpp.o.provides

CMakeFiles/mykmeans.dir/mykmeans.cpp.o.provides.build: CMakeFiles/mykmeans.dir/mykmeans.cpp.o


# Object files for target mykmeans
mykmeans_OBJECTS = \
"CMakeFiles/mykmeans.dir/mykmeans.cpp.o"

# External object files for target mykmeans
mykmeans_EXTERNAL_OBJECTS =

mykmeans: CMakeFiles/mykmeans.dir/mykmeans.cpp.o
mykmeans: CMakeFiles/mykmeans.dir/build.make
mykmeans: /usr/local/lib/libopencv_core.a
mykmeans: /usr/local/lib/libopencv_flann.a
mykmeans: /usr/local/lib/libopencv_imgproc.a
mykmeans: /usr/local/lib/libopencv_highgui.a
mykmeans: /usr/local/lib/libopencv_features2d.a
mykmeans: /usr/local/lib/libopencv_calib3d.a
mykmeans: /usr/local/lib/libopencv_ml.a
mykmeans: /usr/local/lib/libopencv_video.a
mykmeans: /usr/local/lib/libopencv_legacy.a
mykmeans: /usr/local/lib/libopencv_objdetect.a
mykmeans: /usr/local/lib/libopencv_photo.a
mykmeans: /usr/local/lib/libopencv_gpu.a
mykmeans: /usr/local/lib/libopencv_videostab.a
mykmeans: /usr/local/lib/libopencv_ts.a
mykmeans: /usr/local/lib/libopencv_ocl.a
mykmeans: /usr/local/lib/libopencv_superres.a
mykmeans: /usr/local/lib/libopencv_nonfree.a
mykmeans: /usr/local/lib/libopencv_stitching.a
mykmeans: /usr/local/lib/libopencv_contrib.a
mykmeans: /usr/local/lib/libopencv_nonfree.a
mykmeans: /usr/local/lib/libopencv_gpu.a
mykmeans: /usr/local/lib/libopencv_legacy.a
mykmeans: /usr/local/lib/libopencv_photo.a
mykmeans: /usr/local/lib/libopencv_ocl.a
mykmeans: /usr/local/lib/libopencv_calib3d.a
mykmeans: /usr/local/lib/libopencv_features2d.a
mykmeans: /usr/local/lib/libopencv_flann.a
mykmeans: /usr/local/lib/libopencv_ml.a
mykmeans: /usr/local/lib/libopencv_video.a
mykmeans: /usr/local/lib/libopencv_objdetect.a
mykmeans: /usr/local/lib/libopencv_highgui.a
mykmeans: /usr/local/lib/libopencv_imgproc.a
mykmeans: /usr/local/lib/libopencv_core.a
mykmeans: /usr/local/share/OpenCV/3rdparty/lib/liblibjpeg.a
mykmeans: /usr/local/share/OpenCV/3rdparty/lib/liblibpng.a
mykmeans: /usr/local/share/OpenCV/3rdparty/lib/liblibtiff.a
mykmeans: /usr/local/share/OpenCV/3rdparty/lib/liblibjasper.a
mykmeans: /usr/local/share/OpenCV/3rdparty/lib/libIlmImf.a
mykmeans: /usr/local/share/OpenCV/3rdparty/lib/libzlib.a
mykmeans: CMakeFiles/mykmeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/AngelaLee/Documents/senior design/test-opencv/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mykmeans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mykmeans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mykmeans.dir/build: mykmeans

.PHONY : CMakeFiles/mykmeans.dir/build

CMakeFiles/mykmeans.dir/requires: CMakeFiles/mykmeans.dir/mykmeans.cpp.o.requires

.PHONY : CMakeFiles/mykmeans.dir/requires

CMakeFiles/mykmeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mykmeans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mykmeans.dir/clean

CMakeFiles/mykmeans.dir/depend:
	cd "/Users/AngelaLee/Documents/senior design/test-opencv" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv" "/Users/AngelaLee/Documents/senior design/test-opencv/CMakeFiles/mykmeans.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/mykmeans.dir/depend
