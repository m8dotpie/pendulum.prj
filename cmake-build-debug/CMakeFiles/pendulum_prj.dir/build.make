# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/dom_iva/clion-2022.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dom_iva/clion-2022.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dom_iva/Programms/pendulum/pendulum.prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pendulum_prj.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pendulum_prj.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pendulum_prj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pendulum_prj.dir/flags.make

CMakeFiles/pendulum_prj.dir/src/main.c.o: CMakeFiles/pendulum_prj.dir/flags.make
CMakeFiles/pendulum_prj.dir/src/main.c.o: /home/dom_iva/Programms/pendulum/pendulum.prj/src/main.c
CMakeFiles/pendulum_prj.dir/src/main.c.o: CMakeFiles/pendulum_prj.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pendulum_prj.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pendulum_prj.dir/src/main.c.o -MF CMakeFiles/pendulum_prj.dir/src/main.c.o.d -o CMakeFiles/pendulum_prj.dir/src/main.c.o -c /home/dom_iva/Programms/pendulum/pendulum.prj/src/main.c

CMakeFiles/pendulum_prj.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pendulum_prj.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dom_iva/Programms/pendulum/pendulum.prj/src/main.c > CMakeFiles/pendulum_prj.dir/src/main.c.i

CMakeFiles/pendulum_prj.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pendulum_prj.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dom_iva/Programms/pendulum/pendulum.prj/src/main.c -o CMakeFiles/pendulum_prj.dir/src/main.c.s

CMakeFiles/pendulum_prj.dir/src/listener.c.o: CMakeFiles/pendulum_prj.dir/flags.make
CMakeFiles/pendulum_prj.dir/src/listener.c.o: /home/dom_iva/Programms/pendulum/pendulum.prj/src/listener.c
CMakeFiles/pendulum_prj.dir/src/listener.c.o: CMakeFiles/pendulum_prj.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pendulum_prj.dir/src/listener.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pendulum_prj.dir/src/listener.c.o -MF CMakeFiles/pendulum_prj.dir/src/listener.c.o.d -o CMakeFiles/pendulum_prj.dir/src/listener.c.o -c /home/dom_iva/Programms/pendulum/pendulum.prj/src/listener.c

CMakeFiles/pendulum_prj.dir/src/listener.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pendulum_prj.dir/src/listener.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dom_iva/Programms/pendulum/pendulum.prj/src/listener.c > CMakeFiles/pendulum_prj.dir/src/listener.c.i

CMakeFiles/pendulum_prj.dir/src/listener.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pendulum_prj.dir/src/listener.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dom_iva/Programms/pendulum/pendulum.prj/src/listener.c -o CMakeFiles/pendulum_prj.dir/src/listener.c.s

# Object files for target pendulum_prj
pendulum_prj_OBJECTS = \
"CMakeFiles/pendulum_prj.dir/src/main.c.o" \
"CMakeFiles/pendulum_prj.dir/src/listener.c.o"

# External object files for target pendulum_prj
pendulum_prj_EXTERNAL_OBJECTS =

pendulum_prj: CMakeFiles/pendulum_prj.dir/src/main.c.o
pendulum_prj: CMakeFiles/pendulum_prj.dir/src/listener.c.o
pendulum_prj: CMakeFiles/pendulum_prj.dir/build.make
pendulum_prj: libmy_lcmtypes.a
pendulum_prj: /usr/local/lib/liblcm.so.1.4.0
pendulum_prj: CMakeFiles/pendulum_prj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable pendulum_prj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pendulum_prj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pendulum_prj.dir/build: pendulum_prj
.PHONY : CMakeFiles/pendulum_prj.dir/build

CMakeFiles/pendulum_prj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pendulum_prj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pendulum_prj.dir/clean

CMakeFiles/pendulum_prj.dir/depend:
	cd /home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dom_iva/Programms/pendulum/pendulum.prj /home/dom_iva/Programms/pendulum/pendulum.prj /home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug /home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug /home/dom_iva/Programms/pendulum/pendulum.prj/cmake-build-debug/CMakeFiles/pendulum_prj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pendulum_prj.dir/depend
