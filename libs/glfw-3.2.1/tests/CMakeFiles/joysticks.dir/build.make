# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artem/gl/project/libs/glfw-3.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artem/gl/project/libs/glfw-3.2.1

# Include any dependencies generated for this target.
include tests/CMakeFiles/joysticks.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/joysticks.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/joysticks.dir/flags.make

tests/CMakeFiles/joysticks.dir/joysticks.c.o: tests/CMakeFiles/joysticks.dir/flags.make
tests/CMakeFiles/joysticks.dir/joysticks.c.o: tests/joysticks.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/joysticks.dir/joysticks.c.o"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/joysticks.dir/joysticks.c.o   -c /home/artem/gl/project/libs/glfw-3.2.1/tests/joysticks.c

tests/CMakeFiles/joysticks.dir/joysticks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/joysticks.dir/joysticks.c.i"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/artem/gl/project/libs/glfw-3.2.1/tests/joysticks.c > CMakeFiles/joysticks.dir/joysticks.c.i

tests/CMakeFiles/joysticks.dir/joysticks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/joysticks.dir/joysticks.c.s"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/artem/gl/project/libs/glfw-3.2.1/tests/joysticks.c -o CMakeFiles/joysticks.dir/joysticks.c.s

tests/CMakeFiles/joysticks.dir/joysticks.c.o.requires:
.PHONY : tests/CMakeFiles/joysticks.dir/joysticks.c.o.requires

tests/CMakeFiles/joysticks.dir/joysticks.c.o.provides: tests/CMakeFiles/joysticks.dir/joysticks.c.o.requires
	$(MAKE) -f tests/CMakeFiles/joysticks.dir/build.make tests/CMakeFiles/joysticks.dir/joysticks.c.o.provides.build
.PHONY : tests/CMakeFiles/joysticks.dir/joysticks.c.o.provides

tests/CMakeFiles/joysticks.dir/joysticks.c.o.provides.build: tests/CMakeFiles/joysticks.dir/joysticks.c.o

tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o: tests/CMakeFiles/joysticks.dir/flags.make
tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o: deps/glad.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/joysticks.dir/__/deps/glad.c.o   -c /home/artem/gl/project/libs/glfw-3.2.1/deps/glad.c

tests/CMakeFiles/joysticks.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/joysticks.dir/__/deps/glad.c.i"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/artem/gl/project/libs/glfw-3.2.1/deps/glad.c > CMakeFiles/joysticks.dir/__/deps/glad.c.i

tests/CMakeFiles/joysticks.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/joysticks.dir/__/deps/glad.c.s"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/artem/gl/project/libs/glfw-3.2.1/deps/glad.c -o CMakeFiles/joysticks.dir/__/deps/glad.c.s

tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.requires:
.PHONY : tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.requires

tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.provides: tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.requires
	$(MAKE) -f tests/CMakeFiles/joysticks.dir/build.make tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.provides.build
.PHONY : tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.provides

tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.provides.build: tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o

# Object files for target joysticks
joysticks_OBJECTS = \
"CMakeFiles/joysticks.dir/joysticks.c.o" \
"CMakeFiles/joysticks.dir/__/deps/glad.c.o"

# External object files for target joysticks
joysticks_EXTERNAL_OBJECTS =

tests/joysticks: tests/CMakeFiles/joysticks.dir/joysticks.c.o
tests/joysticks: tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o
tests/joysticks: tests/CMakeFiles/joysticks.dir/build.make
tests/joysticks: src/libglfw3.a
tests/joysticks: /usr/lib64/librt.so
tests/joysticks: /usr/lib64/libm.so
tests/joysticks: /usr/lib64/libX11.so
tests/joysticks: /usr/lib64/libXrandr.so
tests/joysticks: /usr/lib64/libXinerama.so
tests/joysticks: /usr/lib64/libXxf86vm.so
tests/joysticks: /usr/lib64/libXcursor.so
tests/joysticks: tests/CMakeFiles/joysticks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable joysticks"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/joysticks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/joysticks.dir/build: tests/joysticks
.PHONY : tests/CMakeFiles/joysticks.dir/build

tests/CMakeFiles/joysticks.dir/requires: tests/CMakeFiles/joysticks.dir/joysticks.c.o.requires
tests/CMakeFiles/joysticks.dir/requires: tests/CMakeFiles/joysticks.dir/__/deps/glad.c.o.requires
.PHONY : tests/CMakeFiles/joysticks.dir/requires

tests/CMakeFiles/joysticks.dir/clean:
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && $(CMAKE_COMMAND) -P CMakeFiles/joysticks.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/joysticks.dir/clean

tests/CMakeFiles/joysticks.dir/depend:
	cd /home/artem/gl/project/libs/glfw-3.2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/gl/project/libs/glfw-3.2.1 /home/artem/gl/project/libs/glfw-3.2.1/tests /home/artem/gl/project/libs/glfw-3.2.1 /home/artem/gl/project/libs/glfw-3.2.1/tests /home/artem/gl/project/libs/glfw-3.2.1/tests/CMakeFiles/joysticks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/joysticks.dir/depend

