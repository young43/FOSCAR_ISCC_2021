# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/young/FOSCAR_ISCC_2021/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/young/FOSCAR_ISCC_2021/build

# Include any dependencies generated for this target.
include serial/CMakeFiles/serial_example.dir/depend.make

# Include the progress variables for this target.
include serial/CMakeFiles/serial_example.dir/progress.make

# Include the compile flags for this target's objects.
include serial/CMakeFiles/serial_example.dir/flags.make

serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o: serial/CMakeFiles/serial_example.dir/flags.make
serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o: /home/young/FOSCAR_ISCC_2021/src/serial/examples/serial_example.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/young/FOSCAR_ISCC_2021/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o"
	cd /home/young/FOSCAR_ISCC_2021/build/serial && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serial_example.dir/examples/serial_example.cc.o -c /home/young/FOSCAR_ISCC_2021/src/serial/examples/serial_example.cc

serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serial_example.dir/examples/serial_example.cc.i"
	cd /home/young/FOSCAR_ISCC_2021/build/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/young/FOSCAR_ISCC_2021/src/serial/examples/serial_example.cc > CMakeFiles/serial_example.dir/examples/serial_example.cc.i

serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serial_example.dir/examples/serial_example.cc.s"
	cd /home/young/FOSCAR_ISCC_2021/build/serial && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/young/FOSCAR_ISCC_2021/src/serial/examples/serial_example.cc -o CMakeFiles/serial_example.dir/examples/serial_example.cc.s

serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.requires:

.PHONY : serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.requires

serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.provides: serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.requires
	$(MAKE) -f serial/CMakeFiles/serial_example.dir/build.make serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.provides.build
.PHONY : serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.provides

serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.provides.build: serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o


# Object files for target serial_example
serial_example_OBJECTS = \
"CMakeFiles/serial_example.dir/examples/serial_example.cc.o"

# External object files for target serial_example
serial_example_EXTERNAL_OBJECTS =

/home/young/FOSCAR_ISCC_2021/devel/lib/serial/serial_example: serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o
/home/young/FOSCAR_ISCC_2021/devel/lib/serial/serial_example: serial/CMakeFiles/serial_example.dir/build.make
/home/young/FOSCAR_ISCC_2021/devel/lib/serial/serial_example: /home/young/FOSCAR_ISCC_2021/devel/lib/libserial.so
/home/young/FOSCAR_ISCC_2021/devel/lib/serial/serial_example: serial/CMakeFiles/serial_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/young/FOSCAR_ISCC_2021/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/young/FOSCAR_ISCC_2021/devel/lib/serial/serial_example"
	cd /home/young/FOSCAR_ISCC_2021/build/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serial_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
serial/CMakeFiles/serial_example.dir/build: /home/young/FOSCAR_ISCC_2021/devel/lib/serial/serial_example

.PHONY : serial/CMakeFiles/serial_example.dir/build

serial/CMakeFiles/serial_example.dir/requires: serial/CMakeFiles/serial_example.dir/examples/serial_example.cc.o.requires

.PHONY : serial/CMakeFiles/serial_example.dir/requires

serial/CMakeFiles/serial_example.dir/clean:
	cd /home/young/FOSCAR_ISCC_2021/build/serial && $(CMAKE_COMMAND) -P CMakeFiles/serial_example.dir/cmake_clean.cmake
.PHONY : serial/CMakeFiles/serial_example.dir/clean

serial/CMakeFiles/serial_example.dir/depend:
	cd /home/young/FOSCAR_ISCC_2021/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/young/FOSCAR_ISCC_2021/src /home/young/FOSCAR_ISCC_2021/src/serial /home/young/FOSCAR_ISCC_2021/build /home/young/FOSCAR_ISCC_2021/build/serial /home/young/FOSCAR_ISCC_2021/build/serial/CMakeFiles/serial_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : serial/CMakeFiles/serial_example.dir/depend

