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
CMAKE_SOURCE_DIR = /home/student/Desktop/OS-HW4/ATAM4/wet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/OS-HW4/ATAM4/wet/build

# Include any dependencies generated for this target.
include CMakeFiles/debugger.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/debugger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/debugger.dir/flags.make

CMakeFiles/debugger.dir/debugger.c.o: CMakeFiles/debugger.dir/flags.make
CMakeFiles/debugger.dir/debugger.c.o: ../debugger.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/OS-HW4/ATAM4/wet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/debugger.dir/debugger.c.o"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/debugger.dir/debugger.c.o   -c /home/student/Desktop/OS-HW4/ATAM4/wet/debugger.c

CMakeFiles/debugger.dir/debugger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/debugger.dir/debugger.c.i"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/Desktop/OS-HW4/ATAM4/wet/debugger.c > CMakeFiles/debugger.dir/debugger.c.i

CMakeFiles/debugger.dir/debugger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/debugger.dir/debugger.c.s"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/Desktop/OS-HW4/ATAM4/wet/debugger.c -o CMakeFiles/debugger.dir/debugger.c.s

CMakeFiles/debugger.dir/debugger.c.o.requires:

.PHONY : CMakeFiles/debugger.dir/debugger.c.o.requires

CMakeFiles/debugger.dir/debugger.c.o.provides: CMakeFiles/debugger.dir/debugger.c.o.requires
	$(MAKE) -f CMakeFiles/debugger.dir/build.make CMakeFiles/debugger.dir/debugger.c.o.provides.build
.PHONY : CMakeFiles/debugger.dir/debugger.c.o.provides

CMakeFiles/debugger.dir/debugger.c.o.provides.build: CMakeFiles/debugger.dir/debugger.c.o


CMakeFiles/debugger.dir/utils.c.o: CMakeFiles/debugger.dir/flags.make
CMakeFiles/debugger.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/OS-HW4/ATAM4/wet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/debugger.dir/utils.c.o"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/debugger.dir/utils.c.o   -c /home/student/Desktop/OS-HW4/ATAM4/wet/utils.c

CMakeFiles/debugger.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/debugger.dir/utils.c.i"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/Desktop/OS-HW4/ATAM4/wet/utils.c > CMakeFiles/debugger.dir/utils.c.i

CMakeFiles/debugger.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/debugger.dir/utils.c.s"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/Desktop/OS-HW4/ATAM4/wet/utils.c -o CMakeFiles/debugger.dir/utils.c.s

CMakeFiles/debugger.dir/utils.c.o.requires:

.PHONY : CMakeFiles/debugger.dir/utils.c.o.requires

CMakeFiles/debugger.dir/utils.c.o.provides: CMakeFiles/debugger.dir/utils.c.o.requires
	$(MAKE) -f CMakeFiles/debugger.dir/build.make CMakeFiles/debugger.dir/utils.c.o.provides.build
.PHONY : CMakeFiles/debugger.dir/utils.c.o.provides

CMakeFiles/debugger.dir/utils.c.o.provides.build: CMakeFiles/debugger.dir/utils.c.o


# Object files for target debugger
debugger_OBJECTS = \
"CMakeFiles/debugger.dir/debugger.c.o" \
"CMakeFiles/debugger.dir/utils.c.o"

# External object files for target debugger
debugger_EXTERNAL_OBJECTS =

debugger: CMakeFiles/debugger.dir/debugger.c.o
debugger: CMakeFiles/debugger.dir/utils.c.o
debugger: CMakeFiles/debugger.dir/build.make
debugger: CMakeFiles/debugger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/OS-HW4/ATAM4/wet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable debugger"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/debugger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/debugger.dir/build: debugger

.PHONY : CMakeFiles/debugger.dir/build

CMakeFiles/debugger.dir/requires: CMakeFiles/debugger.dir/debugger.c.o.requires
CMakeFiles/debugger.dir/requires: CMakeFiles/debugger.dir/utils.c.o.requires

.PHONY : CMakeFiles/debugger.dir/requires

CMakeFiles/debugger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/debugger.dir/cmake_clean.cmake
.PHONY : CMakeFiles/debugger.dir/clean

CMakeFiles/debugger.dir/depend:
	cd /home/student/Desktop/OS-HW4/ATAM4/wet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/OS-HW4/ATAM4/wet /home/student/Desktop/OS-HW4/ATAM4/wet /home/student/Desktop/OS-HW4/ATAM4/wet/build /home/student/Desktop/OS-HW4/ATAM4/wet/build /home/student/Desktop/OS-HW4/ATAM4/wet/build/CMakeFiles/debugger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/debugger.dir/depend

