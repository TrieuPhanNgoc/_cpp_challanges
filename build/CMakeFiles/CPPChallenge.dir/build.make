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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build

# Include any dependencies generated for this target.
include CMakeFiles/CPPChallenge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPPChallenge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPPChallenge.dir/flags.make

CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.o: CMakeFiles/CPPChallenge.dir/flags.make
CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.o: ../HackerRank/Easy/vectorSorting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.o -c /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/HackerRank/Easy/vectorSorting.cpp

CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/HackerRank/Easy/vectorSorting.cpp > CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.i

CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/HackerRank/Easy/vectorSorting.cpp -o CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.s

# Object files for target CPPChallenge
CPPChallenge_OBJECTS = \
"CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.o"

# External object files for target CPPChallenge
CPPChallenge_EXTERNAL_OBJECTS =

CPPChallenge: CMakeFiles/CPPChallenge.dir/HackerRank/Easy/vectorSorting.cpp.o
CPPChallenge: CMakeFiles/CPPChallenge.dir/build.make
CPPChallenge: CMakeFiles/CPPChallenge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPPChallenge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPPChallenge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPPChallenge.dir/build: CPPChallenge

.PHONY : CMakeFiles/CPPChallenge.dir/build

CMakeFiles/CPPChallenge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPPChallenge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPPChallenge.dir/clean

CMakeFiles/CPPChallenge.dir/depend:
	cd /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build /home/trieujohn/Documents/DoingWithGit/Cpp_Challenge/build/CMakeFiles/CPPChallenge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPPChallenge.dir/depend

