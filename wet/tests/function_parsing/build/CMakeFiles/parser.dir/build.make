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
CMAKE_SOURCE_DIR = /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build

# Include any dependencies generated for this target.
include CMakeFiles/parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

CMakeFiles/parser.dir/elf_parser.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/elf_parser.c.o: ../elf_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parser.dir/elf_parser.c.o"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/elf_parser.c.o   -c /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/elf_parser.c

CMakeFiles/parser.dir/elf_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/elf_parser.c.i"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/elf_parser.c > CMakeFiles/parser.dir/elf_parser.c.i

CMakeFiles/parser.dir/elf_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/elf_parser.c.s"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/elf_parser.c -o CMakeFiles/parser.dir/elf_parser.c.s

CMakeFiles/parser.dir/elf_parser.c.o.requires:

.PHONY : CMakeFiles/parser.dir/elf_parser.c.o.requires

CMakeFiles/parser.dir/elf_parser.c.o.provides: CMakeFiles/parser.dir/elf_parser.c.o.requires
	$(MAKE) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/elf_parser.c.o.provides.build
.PHONY : CMakeFiles/parser.dir/elf_parser.c.o.provides

CMakeFiles/parser.dir/elf_parser.c.o.provides.build: CMakeFiles/parser.dir/elf_parser.c.o


CMakeFiles/parser.dir/utils.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/parser.dir/utils.c.o"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/utils.c.o   -c /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/utils.c

CMakeFiles/parser.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/utils.c.i"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/utils.c > CMakeFiles/parser.dir/utils.c.i

CMakeFiles/parser.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/utils.c.s"
	/usr/bin/x86_64-linux-gnu-gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/utils.c -o CMakeFiles/parser.dir/utils.c.s

CMakeFiles/parser.dir/utils.c.o.requires:

.PHONY : CMakeFiles/parser.dir/utils.c.o.requires

CMakeFiles/parser.dir/utils.c.o.provides: CMakeFiles/parser.dir/utils.c.o.requires
	$(MAKE) -f CMakeFiles/parser.dir/build.make CMakeFiles/parser.dir/utils.c.o.provides.build
.PHONY : CMakeFiles/parser.dir/utils.c.o.provides

CMakeFiles/parser.dir/utils.c.o.provides.build: CMakeFiles/parser.dir/utils.c.o


# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/elf_parser.c.o" \
"CMakeFiles/parser.dir/utils.c.o"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

parser: CMakeFiles/parser.dir/elf_parser.c.o
parser: CMakeFiles/parser.dir/utils.c.o
parser: CMakeFiles/parser.dir/build.make
parser: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser

.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/requires: CMakeFiles/parser.dir/elf_parser.c.o.requires
CMakeFiles/parser.dir/requires: CMakeFiles/parser.dir/utils.c.o.requires

.PHONY : CMakeFiles/parser.dir/requires

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend:
	cd /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build /home/student/Desktop/OS-HW4/ATAM4/wet/tests/function_parsing/build/CMakeFiles/parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend
