# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/smerch/projects/tp_project/Space

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/smerch/projects/tp_project/Space/build

# Include any dependencies generated for this target.
include Graphics/CMakeFiles/Graphics_lib.dir/depend.make

# Include the progress variables for this target.
include Graphics/CMakeFiles/Graphics_lib.dir/progress.make

# Include the compile flags for this target's objects.
include Graphics/CMakeFiles/Graphics_lib.dir/flags.make

Graphics/CMakeFiles/Graphics_lib.dir/Graphics.cpp.o: Graphics/CMakeFiles/Graphics_lib.dir/flags.make
Graphics/CMakeFiles/Graphics_lib.dir/Graphics.cpp.o: ../Graphics/Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smerch/projects/tp_project/Space/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Graphics/CMakeFiles/Graphics_lib.dir/Graphics.cpp.o"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Graphics_lib.dir/Graphics.cpp.o -c /home/smerch/projects/tp_project/Space/Graphics/Graphics.cpp

Graphics/CMakeFiles/Graphics_lib.dir/Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graphics_lib.dir/Graphics.cpp.i"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smerch/projects/tp_project/Space/Graphics/Graphics.cpp > CMakeFiles/Graphics_lib.dir/Graphics.cpp.i

Graphics/CMakeFiles/Graphics_lib.dir/Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graphics_lib.dir/Graphics.cpp.s"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smerch/projects/tp_project/Space/Graphics/Graphics.cpp -o CMakeFiles/Graphics_lib.dir/Graphics.cpp.s

Graphics/CMakeFiles/Graphics_lib.dir/Image/Image.cpp.o: Graphics/CMakeFiles/Graphics_lib.dir/flags.make
Graphics/CMakeFiles/Graphics_lib.dir/Image/Image.cpp.o: ../Graphics/Image/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smerch/projects/tp_project/Space/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Graphics/CMakeFiles/Graphics_lib.dir/Image/Image.cpp.o"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Graphics_lib.dir/Image/Image.cpp.o -c /home/smerch/projects/tp_project/Space/Graphics/Image/Image.cpp

Graphics/CMakeFiles/Graphics_lib.dir/Image/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graphics_lib.dir/Image/Image.cpp.i"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smerch/projects/tp_project/Space/Graphics/Image/Image.cpp > CMakeFiles/Graphics_lib.dir/Image/Image.cpp.i

Graphics/CMakeFiles/Graphics_lib.dir/Image/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graphics_lib.dir/Image/Image.cpp.s"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smerch/projects/tp_project/Space/Graphics/Image/Image.cpp -o CMakeFiles/Graphics_lib.dir/Image/Image.cpp.s

Graphics/CMakeFiles/Graphics_lib.dir/Color/Color.cpp.o: Graphics/CMakeFiles/Graphics_lib.dir/flags.make
Graphics/CMakeFiles/Graphics_lib.dir/Color/Color.cpp.o: ../Graphics/Color/Color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/smerch/projects/tp_project/Space/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Graphics/CMakeFiles/Graphics_lib.dir/Color/Color.cpp.o"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Graphics_lib.dir/Color/Color.cpp.o -c /home/smerch/projects/tp_project/Space/Graphics/Color/Color.cpp

Graphics/CMakeFiles/Graphics_lib.dir/Color/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graphics_lib.dir/Color/Color.cpp.i"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/smerch/projects/tp_project/Space/Graphics/Color/Color.cpp > CMakeFiles/Graphics_lib.dir/Color/Color.cpp.i

Graphics/CMakeFiles/Graphics_lib.dir/Color/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graphics_lib.dir/Color/Color.cpp.s"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/smerch/projects/tp_project/Space/Graphics/Color/Color.cpp -o CMakeFiles/Graphics_lib.dir/Color/Color.cpp.s

# Object files for target Graphics_lib
Graphics_lib_OBJECTS = \
"CMakeFiles/Graphics_lib.dir/Graphics.cpp.o" \
"CMakeFiles/Graphics_lib.dir/Image/Image.cpp.o" \
"CMakeFiles/Graphics_lib.dir/Color/Color.cpp.o"

# External object files for target Graphics_lib
Graphics_lib_EXTERNAL_OBJECTS =

../lib/libGraphics_lib.a: Graphics/CMakeFiles/Graphics_lib.dir/Graphics.cpp.o
../lib/libGraphics_lib.a: Graphics/CMakeFiles/Graphics_lib.dir/Image/Image.cpp.o
../lib/libGraphics_lib.a: Graphics/CMakeFiles/Graphics_lib.dir/Color/Color.cpp.o
../lib/libGraphics_lib.a: Graphics/CMakeFiles/Graphics_lib.dir/build.make
../lib/libGraphics_lib.a: Graphics/CMakeFiles/Graphics_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/smerch/projects/tp_project/Space/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../lib/libGraphics_lib.a"
	cd /home/smerch/projects/tp_project/Space/build/Graphics && $(CMAKE_COMMAND) -P CMakeFiles/Graphics_lib.dir/cmake_clean_target.cmake
	cd /home/smerch/projects/tp_project/Space/build/Graphics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Graphics_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Graphics/CMakeFiles/Graphics_lib.dir/build: ../lib/libGraphics_lib.a

.PHONY : Graphics/CMakeFiles/Graphics_lib.dir/build

Graphics/CMakeFiles/Graphics_lib.dir/clean:
	cd /home/smerch/projects/tp_project/Space/build/Graphics && $(CMAKE_COMMAND) -P CMakeFiles/Graphics_lib.dir/cmake_clean.cmake
.PHONY : Graphics/CMakeFiles/Graphics_lib.dir/clean

Graphics/CMakeFiles/Graphics_lib.dir/depend:
	cd /home/smerch/projects/tp_project/Space/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/smerch/projects/tp_project/Space /home/smerch/projects/tp_project/Space/Graphics /home/smerch/projects/tp_project/Space/build /home/smerch/projects/tp_project/Space/build/Graphics /home/smerch/projects/tp_project/Space/build/Graphics/CMakeFiles/Graphics_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Graphics/CMakeFiles/Graphics_lib.dir/depend

