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
CMAKE_SOURCE_DIR = "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build"

# Include any dependencies generated for this target.
include CMakeFiles/bksq_src.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bksq_src.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bksq_src.dir/flags.make

CMakeFiles/bksq_src.dir/bksq.c.o: CMakeFiles/bksq_src.dir/flags.make
CMakeFiles/bksq_src.dir/bksq.c.o: ../bksq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bksq_src.dir/bksq.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bksq_src.dir/bksq.c.o   -c "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/bksq.c"

CMakeFiles/bksq_src.dir/bksq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bksq_src.dir/bksq.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/bksq.c" > CMakeFiles/bksq_src.dir/bksq.c.i

CMakeFiles/bksq_src.dir/bksq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bksq_src.dir/bksq.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/bksq.c" -o CMakeFiles/bksq_src.dir/bksq.c.s

# Object files for target bksq_src
bksq_src_OBJECTS = \
"CMakeFiles/bksq_src.dir/bksq.c.o"

# External object files for target bksq_src
bksq_src_EXTERNAL_OBJECTS =

libbksq_src.a: CMakeFiles/bksq_src.dir/bksq.c.o
libbksq_src.a: CMakeFiles/bksq_src.dir/build.make
libbksq_src.a: CMakeFiles/bksq_src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libbksq_src.a"
	$(CMAKE_COMMAND) -P CMakeFiles/bksq_src.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bksq_src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bksq_src.dir/build: libbksq_src.a

.PHONY : CMakeFiles/bksq_src.dir/build

CMakeFiles/bksq_src.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bksq_src.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bksq_src.dir/clean

CMakeFiles/bksq_src.dir/depend:
	cd "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq" "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq" "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build" "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build" "/home/rose0901/Dokumente/Angewande Kryptologie/Angewandte-Kryptologie/XProgrammieraufgabe/code/bksq/build/CMakeFiles/bksq_src.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bksq_src.dir/depend

