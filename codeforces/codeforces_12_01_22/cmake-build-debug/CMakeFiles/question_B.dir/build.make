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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/question_B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/question_B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/question_B.dir/flags.make

CMakeFiles/question_B.dir/question_B.cpp.o: CMakeFiles/question_B.dir/flags.make
CMakeFiles/question_B.dir/question_B.cpp.o: ../question_B.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/question_B.dir/question_B.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/question_B.dir/question_B.cpp.o -c /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/question_B.cpp

CMakeFiles/question_B.dir/question_B.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question_B.dir/question_B.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/question_B.cpp > CMakeFiles/question_B.dir/question_B.cpp.i

CMakeFiles/question_B.dir/question_B.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question_B.dir/question_B.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/question_B.cpp -o CMakeFiles/question_B.dir/question_B.cpp.s

# Object files for target question_B
question_B_OBJECTS = \
"CMakeFiles/question_B.dir/question_B.cpp.o"

# External object files for target question_B
question_B_EXTERNAL_OBJECTS =

question_B.exe: CMakeFiles/question_B.dir/question_B.cpp.o
question_B.exe: CMakeFiles/question_B.dir/build.make
question_B.exe: CMakeFiles/question_B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable question_B.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/question_B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/question_B.dir/build: question_B.exe

.PHONY : CMakeFiles/question_B.dir/build

CMakeFiles/question_B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/question_B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/question_B.dir/clean

CMakeFiles/question_B.dir/depend:
	cd /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22 /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22 /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug /cygdrive/c/Users/Yuval/CLionProjects/codeforces_12_01_22/cmake-build-debug/CMakeFiles/question_B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/question_B.dir/depend

