# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/keith/CPS2004/Assignment/Task 1/C++"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/keith/CPS2004/Assignment/Task 1/C++/build"

# Include any dependencies generated for this target.
include CMakeFiles/TransportLibrary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TransportLibrary.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TransportLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TransportLibrary.dir/flags.make

CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o: CMakeFiles/TransportLibrary.dir/flags.make
CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o: ../Components/Transport/Transport.cpp
CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o: CMakeFiles/TransportLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/keith/CPS2004/Assignment/Task 1/C++/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o -MF CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o.d -o CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o -c "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/Transport.cpp"

CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/Transport.cpp" > CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.i

CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/Transport.cpp" -o CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.s

CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o: CMakeFiles/TransportLibrary.dir/flags.make
CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o: ../Components/Transport/AirTransport.cpp
CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o: CMakeFiles/TransportLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/keith/CPS2004/Assignment/Task 1/C++/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o -MF CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o.d -o CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o -c "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/AirTransport.cpp"

CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/AirTransport.cpp" > CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.i

CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/AirTransport.cpp" -o CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.s

CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o: CMakeFiles/TransportLibrary.dir/flags.make
CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o: ../Components/Transport/LandTransport.cpp
CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o: CMakeFiles/TransportLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/keith/CPS2004/Assignment/Task 1/C++/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o -MF CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o.d -o CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o -c "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/LandTransport.cpp"

CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/LandTransport.cpp" > CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.i

CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/LandTransport.cpp" -o CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.s

CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o: CMakeFiles/TransportLibrary.dir/flags.make
CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o: ../Components/Transport/SeaTransport.cpp
CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o: CMakeFiles/TransportLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/keith/CPS2004/Assignment/Task 1/C++/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o -MF CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o.d -o CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o -c "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/SeaTransport.cpp"

CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/SeaTransport.cpp" > CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.i

CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/keith/CPS2004/Assignment/Task 1/C++/Components/Transport/SeaTransport.cpp" -o CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.s

# Object files for target TransportLibrary
TransportLibrary_OBJECTS = \
"CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o" \
"CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o" \
"CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o" \
"CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o"

# External object files for target TransportLibrary
TransportLibrary_EXTERNAL_OBJECTS =

libTransportLibrary.a: CMakeFiles/TransportLibrary.dir/Components/Transport/Transport.cpp.o
libTransportLibrary.a: CMakeFiles/TransportLibrary.dir/Components/Transport/AirTransport.cpp.o
libTransportLibrary.a: CMakeFiles/TransportLibrary.dir/Components/Transport/LandTransport.cpp.o
libTransportLibrary.a: CMakeFiles/TransportLibrary.dir/Components/Transport/SeaTransport.cpp.o
libTransportLibrary.a: CMakeFiles/TransportLibrary.dir/build.make
libTransportLibrary.a: CMakeFiles/TransportLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/keith/CPS2004/Assignment/Task 1/C++/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libTransportLibrary.a"
	$(CMAKE_COMMAND) -P CMakeFiles/TransportLibrary.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TransportLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TransportLibrary.dir/build: libTransportLibrary.a
.PHONY : CMakeFiles/TransportLibrary.dir/build

CMakeFiles/TransportLibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TransportLibrary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TransportLibrary.dir/clean

CMakeFiles/TransportLibrary.dir/depend:
	cd "/home/keith/CPS2004/Assignment/Task 1/C++/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/keith/CPS2004/Assignment/Task 1/C++" "/home/keith/CPS2004/Assignment/Task 1/C++" "/home/keith/CPS2004/Assignment/Task 1/C++/build" "/home/keith/CPS2004/Assignment/Task 1/C++/build" "/home/keith/CPS2004/Assignment/Task 1/C++/build/CMakeFiles/TransportLibrary.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TransportLibrary.dir/depend
