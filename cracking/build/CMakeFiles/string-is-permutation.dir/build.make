# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kmmiles/Code/bad-code/cracking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kmmiles/Code/bad-code/cracking/build

# Include any dependencies generated for this target.
include CMakeFiles/string-is-permutation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/string-is-permutation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/string-is-permutation.dir/flags.make

CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.o: CMakeFiles/string-is-permutation.dir/flags.make
CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.o: ../src/string-is-permutation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kmmiles/Code/bad-code/cracking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.o -c /home/kmmiles/Code/bad-code/cracking/src/string-is-permutation.c

CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kmmiles/Code/bad-code/cracking/src/string-is-permutation.c > CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.i

CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kmmiles/Code/bad-code/cracking/src/string-is-permutation.c -o CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.s

# Object files for target string-is-permutation
string__is__permutation_OBJECTS = \
"CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.o"

# External object files for target string-is-permutation
string__is__permutation_EXTERNAL_OBJECTS =

string-is-permutation: CMakeFiles/string-is-permutation.dir/src/string-is-permutation.c.o
string-is-permutation: CMakeFiles/string-is-permutation.dir/build.make
string-is-permutation: CMakeFiles/string-is-permutation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kmmiles/Code/bad-code/cracking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable string-is-permutation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/string-is-permutation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/string-is-permutation.dir/build: string-is-permutation

.PHONY : CMakeFiles/string-is-permutation.dir/build

CMakeFiles/string-is-permutation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/string-is-permutation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/string-is-permutation.dir/clean

CMakeFiles/string-is-permutation.dir/depend:
	cd /home/kmmiles/Code/bad-code/cracking/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kmmiles/Code/bad-code/cracking /home/kmmiles/Code/bad-code/cracking /home/kmmiles/Code/bad-code/cracking/build /home/kmmiles/Code/bad-code/cracking/build /home/kmmiles/Code/bad-code/cracking/build/CMakeFiles/string-is-permutation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/string-is-permutation.dir/depend

