# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dev/CLionProjects/adventure2019/starting_point

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dev/CLionProjects/adventure2019/adventurebuild

# Include any dependencies generated for this target.
include lib/networking/CMakeFiles/networking.dir/depend.make

# Include the progress variables for this target.
include lib/networking/CMakeFiles/networking.dir/progress.make

# Include the compile flags for this target's objects.
include lib/networking/CMakeFiles/networking.dir/flags.make

lib/networking/CMakeFiles/networking.dir/src/Server.cpp.o: lib/networking/CMakeFiles/networking.dir/flags.make
lib/networking/CMakeFiles/networking.dir/src/Server.cpp.o: /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dev/CLionProjects/adventure2019/adventurebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/networking/CMakeFiles/networking.dir/src/Server.cpp.o"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/networking.dir/src/Server.cpp.o -c /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Server.cpp

lib/networking/CMakeFiles/networking.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networking.dir/src/Server.cpp.i"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Server.cpp > CMakeFiles/networking.dir/src/Server.cpp.i

lib/networking/CMakeFiles/networking.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networking.dir/src/Server.cpp.s"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Server.cpp -o CMakeFiles/networking.dir/src/Server.cpp.s

lib/networking/CMakeFiles/networking.dir/src/Client.cpp.o: lib/networking/CMakeFiles/networking.dir/flags.make
lib/networking/CMakeFiles/networking.dir/src/Client.cpp.o: /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dev/CLionProjects/adventure2019/adventurebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/networking/CMakeFiles/networking.dir/src/Client.cpp.o"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/networking.dir/src/Client.cpp.o -c /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Client.cpp

lib/networking/CMakeFiles/networking.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/networking.dir/src/Client.cpp.i"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Client.cpp > CMakeFiles/networking.dir/src/Client.cpp.i

lib/networking/CMakeFiles/networking.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/networking.dir/src/Client.cpp.s"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking/src/Client.cpp -o CMakeFiles/networking.dir/src/Client.cpp.s

# Object files for target networking
networking_OBJECTS = \
"CMakeFiles/networking.dir/src/Server.cpp.o" \
"CMakeFiles/networking.dir/src/Client.cpp.o"

# External object files for target networking
networking_EXTERNAL_OBJECTS =

lib/libnetworking.a: lib/networking/CMakeFiles/networking.dir/src/Server.cpp.o
lib/libnetworking.a: lib/networking/CMakeFiles/networking.dir/src/Client.cpp.o
lib/libnetworking.a: lib/networking/CMakeFiles/networking.dir/build.make
lib/libnetworking.a: lib/networking/CMakeFiles/networking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dev/CLionProjects/adventure2019/adventurebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../libnetworking.a"
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && $(CMAKE_COMMAND) -P CMakeFiles/networking.dir/cmake_clean_target.cmake
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/networking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/networking/CMakeFiles/networking.dir/build: lib/libnetworking.a

.PHONY : lib/networking/CMakeFiles/networking.dir/build

lib/networking/CMakeFiles/networking.dir/clean:
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking && $(CMAKE_COMMAND) -P CMakeFiles/networking.dir/cmake_clean.cmake
.PHONY : lib/networking/CMakeFiles/networking.dir/clean

lib/networking/CMakeFiles/networking.dir/depend:
	cd /Users/dev/CLionProjects/adventure2019/adventurebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dev/CLionProjects/adventure2019/starting_point /Users/dev/CLionProjects/adventure2019/starting_point/lib/networking /Users/dev/CLionProjects/adventure2019/adventurebuild /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking /Users/dev/CLionProjects/adventure2019/adventurebuild/lib/networking/CMakeFiles/networking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/networking/CMakeFiles/networking.dir/depend

