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
CMAKE_SOURCE_DIR = /home/pi/dachuang/QtDemo/QtMavlinkDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug

# Include any dependencies generated for this target.
include CMakeFiles/QtMavlinkDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QtMavlinkDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QtMavlinkDemo.dir/flags.make

CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.o: CMakeFiles/QtMavlinkDemo.dir/flags.make
CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.o: QtMavlinkDemo_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.o -c /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/QtMavlinkDemo_autogen/mocs_compilation.cpp

CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/QtMavlinkDemo_autogen/mocs_compilation.cpp > CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.i

CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/QtMavlinkDemo_autogen/mocs_compilation.cpp -o CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.s

CMakeFiles/QtMavlinkDemo.dir/main.cpp.o: CMakeFiles/QtMavlinkDemo.dir/flags.make
CMakeFiles/QtMavlinkDemo.dir/main.cpp.o: /home/pi/dachuang/QtDemo/QtMavlinkDemo/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QtMavlinkDemo.dir/main.cpp.o"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtMavlinkDemo.dir/main.cpp.o -c /home/pi/dachuang/QtDemo/QtMavlinkDemo/main.cpp

CMakeFiles/QtMavlinkDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtMavlinkDemo.dir/main.cpp.i"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/dachuang/QtDemo/QtMavlinkDemo/main.cpp > CMakeFiles/QtMavlinkDemo.dir/main.cpp.i

CMakeFiles/QtMavlinkDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtMavlinkDemo.dir/main.cpp.s"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/dachuang/QtDemo/QtMavlinkDemo/main.cpp -o CMakeFiles/QtMavlinkDemo.dir/main.cpp.s

CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.o: CMakeFiles/QtMavlinkDemo.dir/flags.make
CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.o: /home/pi/dachuang/QtDemo/QtMavlinkDemo/myserial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.o"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.o -c /home/pi/dachuang/QtDemo/QtMavlinkDemo/myserial.cpp

CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.i"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/dachuang/QtDemo/QtMavlinkDemo/myserial.cpp > CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.i

CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.s"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/dachuang/QtDemo/QtMavlinkDemo/myserial.cpp -o CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.s

CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.o: CMakeFiles/QtMavlinkDemo.dir/flags.make
CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.o: /home/pi/dachuang/QtDemo/QtMavlinkDemo/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.o"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.o -c /home/pi/dachuang/QtDemo/QtMavlinkDemo/mainwindow.cpp

CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.i"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/dachuang/QtDemo/QtMavlinkDemo/mainwindow.cpp > CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.i

CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.s"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/dachuang/QtDemo/QtMavlinkDemo/mainwindow.cpp -o CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.s

CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.o: CMakeFiles/QtMavlinkDemo.dir/flags.make
CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.o: /home/pi/dachuang/QtDemo/QtMavlinkDemo/dialog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.o"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.o -c /home/pi/dachuang/QtDemo/QtMavlinkDemo/dialog.cpp

CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.i"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/dachuang/QtDemo/QtMavlinkDemo/dialog.cpp > CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.i

CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.s"
	/usr/bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/dachuang/QtDemo/QtMavlinkDemo/dialog.cpp -o CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.s

# Object files for target QtMavlinkDemo
QtMavlinkDemo_OBJECTS = \
"CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QtMavlinkDemo.dir/main.cpp.o" \
"CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.o" \
"CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.o" \
"CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.o"

# External object files for target QtMavlinkDemo
QtMavlinkDemo_EXTERNAL_OBJECTS =

QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/QtMavlinkDemo_autogen/mocs_compilation.cpp.o
QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/main.cpp.o
QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/myserial.cpp.o
QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/mainwindow.cpp.o
QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/dialog.cpp.o
QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/build.make
QtMavlinkDemo: /home/pi/dachuang/QtDemo/QtMavlinkDemo/lib/libwiringPi.so
QtMavlinkDemo: /usr/lib/arm-linux-gnueabihf/libQt5Charts.so.5.7.1
QtMavlinkDemo: /usr/lib/arm-linux-gnueabihf/libQt5Widgets.so.5.15.2
QtMavlinkDemo: /usr/lib/arm-linux-gnueabihf/libQt5Gui.so.5.15.2
QtMavlinkDemo: /usr/lib/arm-linux-gnueabihf/libQt5Core.so.5.15.2
QtMavlinkDemo: CMakeFiles/QtMavlinkDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable QtMavlinkDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtMavlinkDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QtMavlinkDemo.dir/build: QtMavlinkDemo

.PHONY : CMakeFiles/QtMavlinkDemo.dir/build

CMakeFiles/QtMavlinkDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtMavlinkDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtMavlinkDemo.dir/clean

CMakeFiles/QtMavlinkDemo.dir/depend:
	cd /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/dachuang/QtDemo/QtMavlinkDemo /home/pi/dachuang/QtDemo/QtMavlinkDemo /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug /home/pi/dachuang/QtDemo/build-QtMavlinkDemo-unknown-Debug/CMakeFiles/QtMavlinkDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QtMavlinkDemo.dir/depend

