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
include tests/CMakeFiles/clipboard.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/clipboard.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/clipboard.dir/flags.make

tests/CMakeFiles/clipboard.dir/clipboard.c.o: tests/CMakeFiles/clipboard.dir/flags.make
tests/CMakeFiles/clipboard.dir/clipboard.c.o: tests/clipboard.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/clipboard.dir/clipboard.c.o"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/clipboard.dir/clipboard.c.o   -c /home/artem/gl/project/libs/glfw-3.2.1/tests/clipboard.c

tests/CMakeFiles/clipboard.dir/clipboard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/clipboard.c.i"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/artem/gl/project/libs/glfw-3.2.1/tests/clipboard.c > CMakeFiles/clipboard.dir/clipboard.c.i

tests/CMakeFiles/clipboard.dir/clipboard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/clipboard.c.s"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/artem/gl/project/libs/glfw-3.2.1/tests/clipboard.c -o CMakeFiles/clipboard.dir/clipboard.c.s

tests/CMakeFiles/clipboard.dir/clipboard.c.o.requires:
.PHONY : tests/CMakeFiles/clipboard.dir/clipboard.c.o.requires

tests/CMakeFiles/clipboard.dir/clipboard.c.o.provides: tests/CMakeFiles/clipboard.dir/clipboard.c.o.requires
	$(MAKE) -f tests/CMakeFiles/clipboard.dir/build.make tests/CMakeFiles/clipboard.dir/clipboard.c.o.provides.build
.PHONY : tests/CMakeFiles/clipboard.dir/clipboard.c.o.provides

tests/CMakeFiles/clipboard.dir/clipboard.c.o.provides.build: tests/CMakeFiles/clipboard.dir/clipboard.c.o

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: tests/CMakeFiles/clipboard.dir/flags.make
tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o: deps/getopt.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/clipboard.dir/__/deps/getopt.c.o   -c /home/artem/gl/project/libs/glfw-3.2.1/deps/getopt.c

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/__/deps/getopt.c.i"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/artem/gl/project/libs/glfw-3.2.1/deps/getopt.c > CMakeFiles/clipboard.dir/__/deps/getopt.c.i

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/__/deps/getopt.c.s"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/artem/gl/project/libs/glfw-3.2.1/deps/getopt.c -o CMakeFiles/clipboard.dir/__/deps/getopt.c.s

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.requires:
.PHONY : tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.requires

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.provides: tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f tests/CMakeFiles/clipboard.dir/build.make tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.provides.build
.PHONY : tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.provides

tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.provides.build: tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o

tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o: tests/CMakeFiles/clipboard.dir/flags.make
tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o: deps/glad.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/artem/gl/project/libs/glfw-3.2.1/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/clipboard.dir/__/deps/glad.c.o   -c /home/artem/gl/project/libs/glfw-3.2.1/deps/glad.c

tests/CMakeFiles/clipboard.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/clipboard.dir/__/deps/glad.c.i"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/artem/gl/project/libs/glfw-3.2.1/deps/glad.c > CMakeFiles/clipboard.dir/__/deps/glad.c.i

tests/CMakeFiles/clipboard.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/clipboard.dir/__/deps/glad.c.s"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && /bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/artem/gl/project/libs/glfw-3.2.1/deps/glad.c -o CMakeFiles/clipboard.dir/__/deps/glad.c.s

tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.requires:
.PHONY : tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.requires

tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.provides: tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.requires
	$(MAKE) -f tests/CMakeFiles/clipboard.dir/build.make tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.provides.build
.PHONY : tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.provides

tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.provides.build: tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o

# Object files for target clipboard
clipboard_OBJECTS = \
"CMakeFiles/clipboard.dir/clipboard.c.o" \
"CMakeFiles/clipboard.dir/__/deps/getopt.c.o" \
"CMakeFiles/clipboard.dir/__/deps/glad.c.o"

# External object files for target clipboard
clipboard_EXTERNAL_OBJECTS =

tests/clipboard: tests/CMakeFiles/clipboard.dir/clipboard.c.o
tests/clipboard: tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o
tests/clipboard: tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o
tests/clipboard: tests/CMakeFiles/clipboard.dir/build.make
tests/clipboard: src/libglfw3.a
tests/clipboard: /usr/lib64/librt.so
tests/clipboard: /usr/lib64/libm.so
tests/clipboard: /usr/lib64/libX11.so
tests/clipboard: /usr/lib64/libXrandr.so
tests/clipboard: /usr/lib64/libXinerama.so
tests/clipboard: /usr/lib64/libXxf86vm.so
tests/clipboard: /usr/lib64/libXcursor.so
tests/clipboard: tests/CMakeFiles/clipboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable clipboard"
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clipboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/clipboard.dir/build: tests/clipboard
.PHONY : tests/CMakeFiles/clipboard.dir/build

tests/CMakeFiles/clipboard.dir/requires: tests/CMakeFiles/clipboard.dir/clipboard.c.o.requires
tests/CMakeFiles/clipboard.dir/requires: tests/CMakeFiles/clipboard.dir/__/deps/getopt.c.o.requires
tests/CMakeFiles/clipboard.dir/requires: tests/CMakeFiles/clipboard.dir/__/deps/glad.c.o.requires
.PHONY : tests/CMakeFiles/clipboard.dir/requires

tests/CMakeFiles/clipboard.dir/clean:
	cd /home/artem/gl/project/libs/glfw-3.2.1/tests && $(CMAKE_COMMAND) -P CMakeFiles/clipboard.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/clipboard.dir/clean

tests/CMakeFiles/clipboard.dir/depend:
	cd /home/artem/gl/project/libs/glfw-3.2.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artem/gl/project/libs/glfw-3.2.1 /home/artem/gl/project/libs/glfw-3.2.1/tests /home/artem/gl/project/libs/glfw-3.2.1 /home/artem/gl/project/libs/glfw-3.2.1/tests /home/artem/gl/project/libs/glfw-3.2.1/tests/CMakeFiles/clipboard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/clipboard.dir/depend

