# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /cygdrive/c/Users/Yuval/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Yuval/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Yuval/CLionProjects/lesson6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lesson6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lesson6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lesson6.dir/flags.make

CMakeFiles/lesson6.dir/all_primes.cpp.o: CMakeFiles/lesson6.dir/flags.make
CMakeFiles/lesson6.dir/all_primes.cpp.o: ../all_primes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lesson6.dir/all_primes.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lesson6.dir/all_primes.cpp.o -c /cygdrive/c/Users/Yuval/CLionProjects/lesson6/all_primes.cpp

CMakeFiles/lesson6.dir/all_primes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lesson6.dir/all_primes.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Yuval/CLionProjects/lesson6/all_primes.cpp > CMakeFiles/lesson6.dir/all_primes.cpp.i

CMakeFiles/lesson6.dir/all_primes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lesson6.dir/all_primes.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Yuval/CLionProjects/lesson6/all_primes.cpp -o CMakeFiles/lesson6.dir/all_primes.cpp.s

# Object files for target lesson6
lesson6_OBJECTS = \
"CMakeFiles/lesson6.dir/all_primes.cpp.o"

# External object files for target lesson6
lesson6_EXTERNAL_OBJECTS =

lesson6.exe: CMakeFiles/lesson6.dir/all_primes.cpp.o
lesson6.exe: CMakeFiles/lesson6.dir/build.make
lesson6.exe: CMakeFiles/lesson6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lesson6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lesson6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lesson6.dir/build: lesson6.exe

.PHONY : CMakeFiles/lesson6.dir/build

CMakeFiles/lesson6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lesson6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lesson6.dir/clean

CMakeFiles/lesson6.dir/depend:
	cd /cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Yuval/CLionProjects/lesson6 /cygdrive/c/Users/Yuval/CLionProjects/lesson6 /cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug /cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug /cygdrive/c/Users/Yuval/CLionProjects/lesson6/cmake-build-debug/CMakeFiles/lesson6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lesson6.dir/depend

