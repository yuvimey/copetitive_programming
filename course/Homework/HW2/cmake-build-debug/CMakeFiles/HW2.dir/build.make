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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Yuval/CLionProjects/HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW2.dir/flags.make

CMakeFiles/HW2.dir/Question_C.cpp.o: CMakeFiles/HW2.dir/flags.make
CMakeFiles/HW2.dir/Question_C.cpp.o: ../Question_C.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW2.dir/Question_C.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW2.dir/Question_C.cpp.o -c /cygdrive/c/Users/Yuval/CLionProjects/HW2/Question_C.cpp

CMakeFiles/HW2.dir/Question_C.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW2.dir/Question_C.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Yuval/CLionProjects/HW2/Question_C.cpp > CMakeFiles/HW2.dir/Question_C.cpp.i

CMakeFiles/HW2.dir/Question_C.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW2.dir/Question_C.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Yuval/CLionProjects/HW2/Question_C.cpp -o CMakeFiles/HW2.dir/Question_C.cpp.s

# Object files for target HW2
HW2_OBJECTS = \
"CMakeFiles/HW2.dir/Question_C.cpp.o"

# External object files for target HW2
HW2_EXTERNAL_OBJECTS =

HW2.exe: CMakeFiles/HW2.dir/Question_C.cpp.o
HW2.exe: CMakeFiles/HW2.dir/build.make
HW2.exe: CMakeFiles/HW2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HW2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW2.dir/build: HW2.exe

.PHONY : CMakeFiles/HW2.dir/build

CMakeFiles/HW2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW2.dir/clean

CMakeFiles/HW2.dir/depend:
	cd /cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Yuval/CLionProjects/HW2 /cygdrive/c/Users/Yuval/CLionProjects/HW2 /cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug /cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug /cygdrive/c/Users/Yuval/CLionProjects/HW2/cmake-build-debug/CMakeFiles/HW2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW2.dir/depend

