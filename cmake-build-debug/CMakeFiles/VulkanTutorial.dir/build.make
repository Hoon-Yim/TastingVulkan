# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/hoon/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/hoon/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hoon/CLionProjects/VulkanTutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VulkanTutorial.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/VulkanTutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VulkanTutorial.dir/flags.make

CMakeFiles/VulkanTutorial.dir/main.cpp.o: CMakeFiles/VulkanTutorial.dir/flags.make
CMakeFiles/VulkanTutorial.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VulkanTutorial.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanTutorial.dir/main.cpp.o -c /Users/hoon/CLionProjects/VulkanTutorial/main.cpp

CMakeFiles/VulkanTutorial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanTutorial.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hoon/CLionProjects/VulkanTutorial/main.cpp > CMakeFiles/VulkanTutorial.dir/main.cpp.i

CMakeFiles/VulkanTutorial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanTutorial.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hoon/CLionProjects/VulkanTutorial/main.cpp -o CMakeFiles/VulkanTutorial.dir/main.cpp.s

CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.o: CMakeFiles/VulkanTutorial.dir/flags.make
CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.o: ../VeWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.o -c /Users/hoon/CLionProjects/VulkanTutorial/VeWindow.cpp

CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hoon/CLionProjects/VulkanTutorial/VeWindow.cpp > CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.i

CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hoon/CLionProjects/VulkanTutorial/VeWindow.cpp -o CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.s

CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.o: CMakeFiles/VulkanTutorial.dir/flags.make
CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.o: ../VeApplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.o -c /Users/hoon/CLionProjects/VulkanTutorial/VeApplication.cpp

CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hoon/CLionProjects/VulkanTutorial/VeApplication.cpp > CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.i

CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hoon/CLionProjects/VulkanTutorial/VeApplication.cpp -o CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.s

# Object files for target VulkanTutorial
VulkanTutorial_OBJECTS = \
"CMakeFiles/VulkanTutorial.dir/main.cpp.o" \
"CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.o" \
"CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.o"

# External object files for target VulkanTutorial
VulkanTutorial_EXTERNAL_OBJECTS =

VulkanTutorial: CMakeFiles/VulkanTutorial.dir/main.cpp.o
VulkanTutorial: CMakeFiles/VulkanTutorial.dir/VeWindow.cpp.o
VulkanTutorial: CMakeFiles/VulkanTutorial.dir/VeApplication.cpp.o
VulkanTutorial: CMakeFiles/VulkanTutorial.dir/build.make
VulkanTutorial: /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.dylib
VulkanTutorial: /usr/local/lib/libvulkan.dylib
VulkanTutorial: CMakeFiles/VulkanTutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable VulkanTutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VulkanTutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VulkanTutorial.dir/build: VulkanTutorial
.PHONY : CMakeFiles/VulkanTutorial.dir/build

CMakeFiles/VulkanTutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VulkanTutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VulkanTutorial.dir/clean

CMakeFiles/VulkanTutorial.dir/depend:
	cd /Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hoon/CLionProjects/VulkanTutorial /Users/hoon/CLionProjects/VulkanTutorial /Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug /Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug /Users/hoon/CLionProjects/VulkanTutorial/cmake-build-debug/CMakeFiles/VulkanTutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VulkanTutorial.dir/depend

