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
CMAKE_COMMAND = /snap/clion/61/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/61/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/Desktop/babka/adventure2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Desktop/babka/adventure2019/cmake-build-debug

# Include any dependencies generated for this target.
include tools/mudclient/CMakeFiles/mudclient.dir/depend.make

# Include the progress variables for this target.
include tools/mudclient/CMakeFiles/mudclient.dir/progress.make

# Include the compile flags for this target's objects.
include tools/mudclient/CMakeFiles/mudclient.dir/flags.make

tools/mudclient/CMakeFiles/mudclient.dir/mudclient.cpp.o: tools/mudclient/CMakeFiles/mudclient.dir/flags.make
tools/mudclient/CMakeFiles/mudclient.dir/mudclient.cpp.o: ../tools/mudclient/mudclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/babka/adventure2019/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/mudclient/CMakeFiles/mudclient.dir/mudclient.cpp.o"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mudclient.dir/mudclient.cpp.o -c /home/alex/Desktop/babka/adventure2019/tools/mudclient/mudclient.cpp

tools/mudclient/CMakeFiles/mudclient.dir/mudclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mudclient.dir/mudclient.cpp.i"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/babka/adventure2019/tools/mudclient/mudclient.cpp > CMakeFiles/mudclient.dir/mudclient.cpp.i

tools/mudclient/CMakeFiles/mudclient.dir/mudclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mudclient.dir/mudclient.cpp.s"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/babka/adventure2019/tools/mudclient/mudclient.cpp -o CMakeFiles/mudclient.dir/mudclient.cpp.s

tools/mudclient/CMakeFiles/mudclient.dir/ChatWindow.cpp.o: tools/mudclient/CMakeFiles/mudclient.dir/flags.make
tools/mudclient/CMakeFiles/mudclient.dir/ChatWindow.cpp.o: ../tools/mudclient/ChatWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/babka/adventure2019/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tools/mudclient/CMakeFiles/mudclient.dir/ChatWindow.cpp.o"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mudclient.dir/ChatWindow.cpp.o -c /home/alex/Desktop/babka/adventure2019/tools/mudclient/ChatWindow.cpp

tools/mudclient/CMakeFiles/mudclient.dir/ChatWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mudclient.dir/ChatWindow.cpp.i"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/babka/adventure2019/tools/mudclient/ChatWindow.cpp > CMakeFiles/mudclient.dir/ChatWindow.cpp.i

tools/mudclient/CMakeFiles/mudclient.dir/ChatWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mudclient.dir/ChatWindow.cpp.s"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/babka/adventure2019/tools/mudclient/ChatWindow.cpp -o CMakeFiles/mudclient.dir/ChatWindow.cpp.s

# Object files for target mudclient
mudclient_OBJECTS = \
"CMakeFiles/mudclient.dir/mudclient.cpp.o" \
"CMakeFiles/mudclient.dir/ChatWindow.cpp.o"

# External object files for target mudclient
mudclient_EXTERNAL_OBJECTS =

bin/mudclient: tools/mudclient/CMakeFiles/mudclient.dir/mudclient.cpp.o
bin/mudclient: tools/mudclient/CMakeFiles/mudclient.dir/ChatWindow.cpp.o
bin/mudclient: tools/mudclient/CMakeFiles/mudclient.dir/build.make
bin/mudclient: lib/libnetworking.a
bin/mudclient: /usr/lib/x86_64-linux-gnu/libcurses.so
bin/mudclient: /usr/lib/x86_64-linux-gnu/libform.so
bin/mudclient: /usr/local/lib/libboost_system.so
bin/mudclient: tools/mudclient/CMakeFiles/mudclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Desktop/babka/adventure2019/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/mudclient"
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mudclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/mudclient/CMakeFiles/mudclient.dir/build: bin/mudclient

.PHONY : tools/mudclient/CMakeFiles/mudclient.dir/build

tools/mudclient/CMakeFiles/mudclient.dir/clean:
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient && $(CMAKE_COMMAND) -P CMakeFiles/mudclient.dir/cmake_clean.cmake
.PHONY : tools/mudclient/CMakeFiles/mudclient.dir/clean

tools/mudclient/CMakeFiles/mudclient.dir/depend:
	cd /home/alex/Desktop/babka/adventure2019/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Desktop/babka/adventure2019 /home/alex/Desktop/babka/adventure2019/tools/mudclient /home/alex/Desktop/babka/adventure2019/cmake-build-debug /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient /home/alex/Desktop/babka/adventure2019/cmake-build-debug/tools/mudclient/CMakeFiles/mudclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/mudclient/CMakeFiles/mudclient.dir/depend

