# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /home/seb/.bin/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/seb/.bin/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/seb/tmp/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/seb/tmp/Client

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/seb/.bin/clion-2018.1.2/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/seb/.bin/clion-2018.1.2/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/seb/tmp/Client/CMakeFiles /home/seb/tmp/Client/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/seb/tmp/Client/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Client

# Build rule for target.
Client: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Client
.PHONY : Client

# fast build rule for target.
Client/fast:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/build
.PHONY : Client/fast

libs/Json/srcs/Entity/Entity.o: libs/Json/srcs/Entity/Entity.cpp.o

.PHONY : libs/Json/srcs/Entity/Entity.o

# target to build an object file
libs/Json/srcs/Entity/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/srcs/Entity/Entity.cpp.o
.PHONY : libs/Json/srcs/Entity/Entity.cpp.o

libs/Json/srcs/Entity/Entity.i: libs/Json/srcs/Entity/Entity.cpp.i

.PHONY : libs/Json/srcs/Entity/Entity.i

# target to preprocess a source file
libs/Json/srcs/Entity/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/srcs/Entity/Entity.cpp.i
.PHONY : libs/Json/srcs/Entity/Entity.cpp.i

libs/Json/srcs/Entity/Entity.s: libs/Json/srcs/Entity/Entity.cpp.s

.PHONY : libs/Json/srcs/Entity/Entity.s

# target to generate assembly for a file
libs/Json/srcs/Entity/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/srcs/Entity/Entity.cpp.s
.PHONY : libs/Json/srcs/Entity/Entity.cpp.s

libs/Json/srcs/Parser/Parser.o: libs/Json/srcs/Parser/Parser.cpp.o

.PHONY : libs/Json/srcs/Parser/Parser.o

# target to build an object file
libs/Json/srcs/Parser/Parser.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/srcs/Parser/Parser.cpp.o
.PHONY : libs/Json/srcs/Parser/Parser.cpp.o

libs/Json/srcs/Parser/Parser.i: libs/Json/srcs/Parser/Parser.cpp.i

.PHONY : libs/Json/srcs/Parser/Parser.i

# target to preprocess a source file
libs/Json/srcs/Parser/Parser.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/srcs/Parser/Parser.cpp.i
.PHONY : libs/Json/srcs/Parser/Parser.cpp.i

libs/Json/srcs/Parser/Parser.s: libs/Json/srcs/Parser/Parser.cpp.s

.PHONY : libs/Json/srcs/Parser/Parser.s

# target to generate assembly for a file
libs/Json/srcs/Parser/Parser.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/srcs/Parser/Parser.cpp.s
.PHONY : libs/Json/srcs/Parser/Parser.cpp.s

libs/Json/tests/Entity/main.o: libs/Json/tests/Entity/main.cpp.o

.PHONY : libs/Json/tests/Entity/main.o

# target to build an object file
libs/Json/tests/Entity/main.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Entity/main.cpp.o
.PHONY : libs/Json/tests/Entity/main.cpp.o

libs/Json/tests/Entity/main.i: libs/Json/tests/Entity/main.cpp.i

.PHONY : libs/Json/tests/Entity/main.i

# target to preprocess a source file
libs/Json/tests/Entity/main.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Entity/main.cpp.i
.PHONY : libs/Json/tests/Entity/main.cpp.i

libs/Json/tests/Entity/main.s: libs/Json/tests/Entity/main.cpp.s

.PHONY : libs/Json/tests/Entity/main.s

# target to generate assembly for a file
libs/Json/tests/Entity/main.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Entity/main.cpp.s
.PHONY : libs/Json/tests/Entity/main.cpp.s

libs/Json/tests/Parser/main.o: libs/Json/tests/Parser/main.cpp.o

.PHONY : libs/Json/tests/Parser/main.o

# target to build an object file
libs/Json/tests/Parser/main.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/main.cpp.o
.PHONY : libs/Json/tests/Parser/main.cpp.o

libs/Json/tests/Parser/main.i: libs/Json/tests/Parser/main.cpp.i

.PHONY : libs/Json/tests/Parser/main.i

# target to preprocess a source file
libs/Json/tests/Parser/main.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/main.cpp.i
.PHONY : libs/Json/tests/Parser/main.cpp.i

libs/Json/tests/Parser/main.s: libs/Json/tests/Parser/main.cpp.s

.PHONY : libs/Json/tests/Parser/main.s

# target to generate assembly for a file
libs/Json/tests/Parser/main.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/main.cpp.s
.PHONY : libs/Json/tests/Parser/main.cpp.s

libs/Json/tests/Parser/srcs/Entity/Entity.o: libs/Json/tests/Parser/srcs/Entity/Entity.cpp.o

.PHONY : libs/Json/tests/Parser/srcs/Entity/Entity.o

# target to build an object file
libs/Json/tests/Parser/srcs/Entity/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/srcs/Entity/Entity.cpp.o
.PHONY : libs/Json/tests/Parser/srcs/Entity/Entity.cpp.o

libs/Json/tests/Parser/srcs/Entity/Entity.i: libs/Json/tests/Parser/srcs/Entity/Entity.cpp.i

.PHONY : libs/Json/tests/Parser/srcs/Entity/Entity.i

# target to preprocess a source file
libs/Json/tests/Parser/srcs/Entity/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/srcs/Entity/Entity.cpp.i
.PHONY : libs/Json/tests/Parser/srcs/Entity/Entity.cpp.i

libs/Json/tests/Parser/srcs/Entity/Entity.s: libs/Json/tests/Parser/srcs/Entity/Entity.cpp.s

.PHONY : libs/Json/tests/Parser/srcs/Entity/Entity.s

# target to generate assembly for a file
libs/Json/tests/Parser/srcs/Entity/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/srcs/Entity/Entity.cpp.s
.PHONY : libs/Json/tests/Parser/srcs/Entity/Entity.cpp.s

libs/Json/tests/Parser/srcs/Parser/Parser.o: libs/Json/tests/Parser/srcs/Parser/Parser.cpp.o

.PHONY : libs/Json/tests/Parser/srcs/Parser/Parser.o

# target to build an object file
libs/Json/tests/Parser/srcs/Parser/Parser.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/srcs/Parser/Parser.cpp.o
.PHONY : libs/Json/tests/Parser/srcs/Parser/Parser.cpp.o

libs/Json/tests/Parser/srcs/Parser/Parser.i: libs/Json/tests/Parser/srcs/Parser/Parser.cpp.i

.PHONY : libs/Json/tests/Parser/srcs/Parser/Parser.i

# target to preprocess a source file
libs/Json/tests/Parser/srcs/Parser/Parser.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/srcs/Parser/Parser.cpp.i
.PHONY : libs/Json/tests/Parser/srcs/Parser/Parser.cpp.i

libs/Json/tests/Parser/srcs/Parser/Parser.s: libs/Json/tests/Parser/srcs/Parser/Parser.cpp.s

.PHONY : libs/Json/tests/Parser/srcs/Parser/Parser.s

# target to generate assembly for a file
libs/Json/tests/Parser/srcs/Parser/Parser.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/Json/tests/Parser/srcs/Parser/Parser.cpp.s
.PHONY : libs/Json/tests/Parser/srcs/Parser/Parser.cpp.s

libs/SmartEvent/srcs/Event/Event.o: libs/SmartEvent/srcs/Event/Event.cpp.o

.PHONY : libs/SmartEvent/srcs/Event/Event.o

# target to build an object file
libs/SmartEvent/srcs/Event/Event.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/srcs/Event/Event.cpp.o
.PHONY : libs/SmartEvent/srcs/Event/Event.cpp.o

libs/SmartEvent/srcs/Event/Event.i: libs/SmartEvent/srcs/Event/Event.cpp.i

.PHONY : libs/SmartEvent/srcs/Event/Event.i

# target to preprocess a source file
libs/SmartEvent/srcs/Event/Event.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/srcs/Event/Event.cpp.i
.PHONY : libs/SmartEvent/srcs/Event/Event.cpp.i

libs/SmartEvent/srcs/Event/Event.s: libs/SmartEvent/srcs/Event/Event.cpp.s

.PHONY : libs/SmartEvent/srcs/Event/Event.s

# target to generate assembly for a file
libs/SmartEvent/srcs/Event/Event.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/srcs/Event/Event.cpp.s
.PHONY : libs/SmartEvent/srcs/Event/Event.cpp.s

libs/SmartEvent/srcs/HdlCollector/HdlCollector.o: libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.o

.PHONY : libs/SmartEvent/srcs/HdlCollector/HdlCollector.o

# target to build an object file
libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.o
.PHONY : libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.o

libs/SmartEvent/srcs/HdlCollector/HdlCollector.i: libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.i

.PHONY : libs/SmartEvent/srcs/HdlCollector/HdlCollector.i

# target to preprocess a source file
libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.i
.PHONY : libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.i

libs/SmartEvent/srcs/HdlCollector/HdlCollector.s: libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.s

.PHONY : libs/SmartEvent/srcs/HdlCollector/HdlCollector.s

# target to generate assembly for a file
libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.s
.PHONY : libs/SmartEvent/srcs/HdlCollector/HdlCollector.cpp.s

libs/SmartEvent/tests/Event/main.o: libs/SmartEvent/tests/Event/main.cpp.o

.PHONY : libs/SmartEvent/tests/Event/main.o

# target to build an object file
libs/SmartEvent/tests/Event/main.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/tests/Event/main.cpp.o
.PHONY : libs/SmartEvent/tests/Event/main.cpp.o

libs/SmartEvent/tests/Event/main.i: libs/SmartEvent/tests/Event/main.cpp.i

.PHONY : libs/SmartEvent/tests/Event/main.i

# target to preprocess a source file
libs/SmartEvent/tests/Event/main.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/tests/Event/main.cpp.i
.PHONY : libs/SmartEvent/tests/Event/main.cpp.i

libs/SmartEvent/tests/Event/main.s: libs/SmartEvent/tests/Event/main.cpp.s

.PHONY : libs/SmartEvent/tests/Event/main.s

# target to generate assembly for a file
libs/SmartEvent/tests/Event/main.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/tests/Event/main.cpp.s
.PHONY : libs/SmartEvent/tests/Event/main.cpp.s

libs/SmartEvent/tests/HdlCollector/main.o: libs/SmartEvent/tests/HdlCollector/main.cpp.o

.PHONY : libs/SmartEvent/tests/HdlCollector/main.o

# target to build an object file
libs/SmartEvent/tests/HdlCollector/main.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/tests/HdlCollector/main.cpp.o
.PHONY : libs/SmartEvent/tests/HdlCollector/main.cpp.o

libs/SmartEvent/tests/HdlCollector/main.i: libs/SmartEvent/tests/HdlCollector/main.cpp.i

.PHONY : libs/SmartEvent/tests/HdlCollector/main.i

# target to preprocess a source file
libs/SmartEvent/tests/HdlCollector/main.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/tests/HdlCollector/main.cpp.i
.PHONY : libs/SmartEvent/tests/HdlCollector/main.cpp.i

libs/SmartEvent/tests/HdlCollector/main.s: libs/SmartEvent/tests/HdlCollector/main.cpp.s

.PHONY : libs/SmartEvent/tests/HdlCollector/main.s

# target to generate assembly for a file
libs/SmartEvent/tests/HdlCollector/main.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/libs/SmartEvent/tests/HdlCollector/main.cpp.s
.PHONY : libs/SmartEvent/tests/HdlCollector/main.cpp.s

srcs/Console/Console.o: srcs/Console/Console.cpp.o

.PHONY : srcs/Console/Console.o

# target to build an object file
srcs/Console/Console.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Console/Console.cpp.o
.PHONY : srcs/Console/Console.cpp.o

srcs/Console/Console.i: srcs/Console/Console.cpp.i

.PHONY : srcs/Console/Console.i

# target to preprocess a source file
srcs/Console/Console.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Console/Console.cpp.i
.PHONY : srcs/Console/Console.cpp.i

srcs/Console/Console.s: srcs/Console/Console.cpp.s

.PHONY : srcs/Console/Console.s

# target to generate assembly for a file
srcs/Console/Console.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Console/Console.cpp.s
.PHONY : srcs/Console/Console.cpp.s

srcs/ECS/Entity/Entity.o: srcs/ECS/Entity/Entity.cpp.o

.PHONY : srcs/ECS/Entity/Entity.o

# target to build an object file
srcs/ECS/Entity/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/ECS/Entity/Entity.cpp.o
.PHONY : srcs/ECS/Entity/Entity.cpp.o

srcs/ECS/Entity/Entity.i: srcs/ECS/Entity/Entity.cpp.i

.PHONY : srcs/ECS/Entity/Entity.i

# target to preprocess a source file
srcs/ECS/Entity/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/ECS/Entity/Entity.cpp.i
.PHONY : srcs/ECS/Entity/Entity.cpp.i

srcs/ECS/Entity/Entity.s: srcs/ECS/Entity/Entity.cpp.s

.PHONY : srcs/ECS/Entity/Entity.s

# target to generate assembly for a file
srcs/ECS/Entity/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/ECS/Entity/Entity.cpp.s
.PHONY : srcs/ECS/Entity/Entity.cpp.s

srcs/Game/Game.o: srcs/Game/Game.cpp.o

.PHONY : srcs/Game/Game.o

# target to build an object file
srcs/Game/Game.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Game/Game.cpp.o
.PHONY : srcs/Game/Game.cpp.o

srcs/Game/Game.i: srcs/Game/Game.cpp.i

.PHONY : srcs/Game/Game.i

# target to preprocess a source file
srcs/Game/Game.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Game/Game.cpp.i
.PHONY : srcs/Game/Game.cpp.i

srcs/Game/Game.s: srcs/Game/Game.cpp.s

.PHONY : srcs/Game/Game.s

# target to generate assembly for a file
srcs/Game/Game.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Game/Game.cpp.s
.PHONY : srcs/Game/Game.cpp.s

srcs/Graphical/EventReceiver.o: srcs/Graphical/EventReceiver.cpp.o

.PHONY : srcs/Graphical/EventReceiver.o

# target to build an object file
srcs/Graphical/EventReceiver.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Graphical/EventReceiver.cpp.o
.PHONY : srcs/Graphical/EventReceiver.cpp.o

srcs/Graphical/EventReceiver.i: srcs/Graphical/EventReceiver.cpp.i

.PHONY : srcs/Graphical/EventReceiver.i

# target to preprocess a source file
srcs/Graphical/EventReceiver.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Graphical/EventReceiver.cpp.i
.PHONY : srcs/Graphical/EventReceiver.cpp.i

srcs/Graphical/EventReceiver.s: srcs/Graphical/EventReceiver.cpp.s

.PHONY : srcs/Graphical/EventReceiver.s

# target to generate assembly for a file
srcs/Graphical/EventReceiver.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Graphical/EventReceiver.cpp.s
.PHONY : srcs/Graphical/EventReceiver.cpp.s

srcs/MapGen/mapGen.o: srcs/MapGen/mapGen.cpp.o

.PHONY : srcs/MapGen/mapGen.o

# target to build an object file
srcs/MapGen/mapGen.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/MapGen/mapGen.cpp.o
.PHONY : srcs/MapGen/mapGen.cpp.o

srcs/MapGen/mapGen.i: srcs/MapGen/mapGen.cpp.i

.PHONY : srcs/MapGen/mapGen.i

# target to preprocess a source file
srcs/MapGen/mapGen.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/MapGen/mapGen.cpp.i
.PHONY : srcs/MapGen/mapGen.cpp.i

srcs/MapGen/mapGen.s: srcs/MapGen/mapGen.cpp.s

.PHONY : srcs/MapGen/mapGen.s

# target to generate assembly for a file
srcs/MapGen/mapGen.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/MapGen/mapGen.cpp.s
.PHONY : srcs/MapGen/mapGen.cpp.s

srcs/Settings/Inputs.o: srcs/Settings/Inputs.cpp.o

.PHONY : srcs/Settings/Inputs.o

# target to build an object file
srcs/Settings/Inputs.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Settings/Inputs.cpp.o
.PHONY : srcs/Settings/Inputs.cpp.o

srcs/Settings/Inputs.i: srcs/Settings/Inputs.cpp.i

.PHONY : srcs/Settings/Inputs.i

# target to preprocess a source file
srcs/Settings/Inputs.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Settings/Inputs.cpp.i
.PHONY : srcs/Settings/Inputs.cpp.i

srcs/Settings/Inputs.s: srcs/Settings/Inputs.cpp.s

.PHONY : srcs/Settings/Inputs.s

# target to generate assembly for a file
srcs/Settings/Inputs.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Settings/Inputs.cpp.s
.PHONY : srcs/Settings/Inputs.cpp.s

srcs/Settings/Settings.o: srcs/Settings/Settings.cpp.o

.PHONY : srcs/Settings/Settings.o

# target to build an object file
srcs/Settings/Settings.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Settings/Settings.cpp.o
.PHONY : srcs/Settings/Settings.cpp.o

srcs/Settings/Settings.i: srcs/Settings/Settings.cpp.i

.PHONY : srcs/Settings/Settings.i

# target to preprocess a source file
srcs/Settings/Settings.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Settings/Settings.cpp.i
.PHONY : srcs/Settings/Settings.cpp.i

srcs/Settings/Settings.s: srcs/Settings/Settings.cpp.s

.PHONY : srcs/Settings/Settings.s

# target to generate assembly for a file
srcs/Settings/Settings.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/Settings/Settings.cpp.s
.PHONY : srcs/Settings/Settings.cpp.s

srcs/System/Being.o: srcs/System/Being.cpp.o

.PHONY : srcs/System/Being.o

# target to build an object file
srcs/System/Being.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/Being.cpp.o
.PHONY : srcs/System/Being.cpp.o

srcs/System/Being.i: srcs/System/Being.cpp.i

.PHONY : srcs/System/Being.i

# target to preprocess a source file
srcs/System/Being.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/Being.cpp.i
.PHONY : srcs/System/Being.cpp.i

srcs/System/Being.s: srcs/System/Being.cpp.s

.PHONY : srcs/System/Being.s

# target to generate assembly for a file
srcs/System/Being.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/Being.cpp.s
.PHONY : srcs/System/Being.cpp.s

srcs/System/Create.o: srcs/System/Create.cpp.o

.PHONY : srcs/System/Create.o

# target to build an object file
srcs/System/Create.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/Create.cpp.o
.PHONY : srcs/System/Create.cpp.o

srcs/System/Create.i: srcs/System/Create.cpp.i

.PHONY : srcs/System/Create.i

# target to preprocess a source file
srcs/System/Create.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/Create.cpp.i
.PHONY : srcs/System/Create.cpp.i

srcs/System/Create.s: srcs/System/Create.cpp.s

.PHONY : srcs/System/Create.s

# target to generate assembly for a file
srcs/System/Create.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/Create.cpp.s
.PHONY : srcs/System/Create.cpp.s

srcs/System/EventManager.o: srcs/System/EventManager.cpp.o

.PHONY : srcs/System/EventManager.o

# target to build an object file
srcs/System/EventManager.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/EventManager.cpp.o
.PHONY : srcs/System/EventManager.cpp.o

srcs/System/EventManager.i: srcs/System/EventManager.cpp.i

.PHONY : srcs/System/EventManager.i

# target to preprocess a source file
srcs/System/EventManager.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/EventManager.cpp.i
.PHONY : srcs/System/EventManager.cpp.i

srcs/System/EventManager.s: srcs/System/EventManager.cpp.s

.PHONY : srcs/System/EventManager.s

# target to generate assembly for a file
srcs/System/EventManager.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/EventManager.cpp.s
.PHONY : srcs/System/EventManager.cpp.s

srcs/System/UpdateDeplacement.o: srcs/System/UpdateDeplacement.cpp.o

.PHONY : srcs/System/UpdateDeplacement.o

# target to build an object file
srcs/System/UpdateDeplacement.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/UpdateDeplacement.cpp.o
.PHONY : srcs/System/UpdateDeplacement.cpp.o

srcs/System/UpdateDeplacement.i: srcs/System/UpdateDeplacement.cpp.i

.PHONY : srcs/System/UpdateDeplacement.i

# target to preprocess a source file
srcs/System/UpdateDeplacement.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/UpdateDeplacement.cpp.i
.PHONY : srcs/System/UpdateDeplacement.cpp.i

srcs/System/UpdateDeplacement.s: srcs/System/UpdateDeplacement.cpp.s

.PHONY : srcs/System/UpdateDeplacement.s

# target to generate assembly for a file
srcs/System/UpdateDeplacement.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/srcs/System/UpdateDeplacement.cpp.s
.PHONY : srcs/System/UpdateDeplacement.cpp.s

tests/bla.o: tests/bla.cpp.o

.PHONY : tests/bla.o

# target to build an object file
tests/bla.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/tests/bla.cpp.o
.PHONY : tests/bla.cpp.o

tests/bla.i: tests/bla.cpp.i

.PHONY : tests/bla.i

# target to preprocess a source file
tests/bla.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/tests/bla.cpp.i
.PHONY : tests/bla.cpp.i

tests/bla.s: tests/bla.cpp.s

.PHONY : tests/bla.s

# target to generate assembly for a file
tests/bla.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/tests/bla.cpp.s
.PHONY : tests/bla.cpp.s

tests/graphicalTest/test.o: tests/graphicalTest/test.cpp.o

.PHONY : tests/graphicalTest/test.o

# target to build an object file
tests/graphicalTest/test.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/tests/graphicalTest/test.cpp.o
.PHONY : tests/graphicalTest/test.cpp.o

tests/graphicalTest/test.i: tests/graphicalTest/test.cpp.i

.PHONY : tests/graphicalTest/test.i

# target to preprocess a source file
tests/graphicalTest/test.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/tests/graphicalTest/test.cpp.i
.PHONY : tests/graphicalTest/test.cpp.i

tests/graphicalTest/test.s: tests/graphicalTest/test.cpp.s

.PHONY : tests/graphicalTest/test.s

# target to generate assembly for a file
tests/graphicalTest/test.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/tests/graphicalTest/test.cpp.s
.PHONY : tests/graphicalTest/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Client"
	@echo "... libs/Json/srcs/Entity/Entity.o"
	@echo "... libs/Json/srcs/Entity/Entity.i"
	@echo "... libs/Json/srcs/Entity/Entity.s"
	@echo "... libs/Json/srcs/Parser/Parser.o"
	@echo "... libs/Json/srcs/Parser/Parser.i"
	@echo "... libs/Json/srcs/Parser/Parser.s"
	@echo "... libs/Json/tests/Entity/main.o"
	@echo "... libs/Json/tests/Entity/main.i"
	@echo "... libs/Json/tests/Entity/main.s"
	@echo "... libs/Json/tests/Parser/main.o"
	@echo "... libs/Json/tests/Parser/main.i"
	@echo "... libs/Json/tests/Parser/main.s"
	@echo "... libs/Json/tests/Parser/srcs/Entity/Entity.o"
	@echo "... libs/Json/tests/Parser/srcs/Entity/Entity.i"
	@echo "... libs/Json/tests/Parser/srcs/Entity/Entity.s"
	@echo "... libs/Json/tests/Parser/srcs/Parser/Parser.o"
	@echo "... libs/Json/tests/Parser/srcs/Parser/Parser.i"
	@echo "... libs/Json/tests/Parser/srcs/Parser/Parser.s"
	@echo "... libs/SmartEvent/srcs/Event/Event.o"
	@echo "... libs/SmartEvent/srcs/Event/Event.i"
	@echo "... libs/SmartEvent/srcs/Event/Event.s"
	@echo "... libs/SmartEvent/srcs/HdlCollector/HdlCollector.o"
	@echo "... libs/SmartEvent/srcs/HdlCollector/HdlCollector.i"
	@echo "... libs/SmartEvent/srcs/HdlCollector/HdlCollector.s"
	@echo "... libs/SmartEvent/tests/Event/main.o"
	@echo "... libs/SmartEvent/tests/Event/main.i"
	@echo "... libs/SmartEvent/tests/Event/main.s"
	@echo "... libs/SmartEvent/tests/HdlCollector/main.o"
	@echo "... libs/SmartEvent/tests/HdlCollector/main.i"
	@echo "... libs/SmartEvent/tests/HdlCollector/main.s"
	@echo "... srcs/Console/Console.o"
	@echo "... srcs/Console/Console.i"
	@echo "... srcs/Console/Console.s"
	@echo "... srcs/ECS/Entity/Entity.o"
	@echo "... srcs/ECS/Entity/Entity.i"
	@echo "... srcs/ECS/Entity/Entity.s"
	@echo "... srcs/Game/Game.o"
	@echo "... srcs/Game/Game.i"
	@echo "... srcs/Game/Game.s"
	@echo "... srcs/Graphical/EventReceiver.o"
	@echo "... srcs/Graphical/EventReceiver.i"
	@echo "... srcs/Graphical/EventReceiver.s"
	@echo "... srcs/MapGen/mapGen.o"
	@echo "... srcs/MapGen/mapGen.i"
	@echo "... srcs/MapGen/mapGen.s"
	@echo "... srcs/Settings/Inputs.o"
	@echo "... srcs/Settings/Inputs.i"
	@echo "... srcs/Settings/Inputs.s"
	@echo "... srcs/Settings/Settings.o"
	@echo "... srcs/Settings/Settings.i"
	@echo "... srcs/Settings/Settings.s"
	@echo "... srcs/System/Being.o"
	@echo "... srcs/System/Being.i"
	@echo "... srcs/System/Being.s"
	@echo "... srcs/System/Create.o"
	@echo "... srcs/System/Create.i"
	@echo "... srcs/System/Create.s"
	@echo "... srcs/System/EventManager.o"
	@echo "... srcs/System/EventManager.i"
	@echo "... srcs/System/EventManager.s"
	@echo "... srcs/System/UpdateDeplacement.o"
	@echo "... srcs/System/UpdateDeplacement.i"
	@echo "... srcs/System/UpdateDeplacement.s"
	@echo "... tests/bla.o"
	@echo "... tests/bla.i"
	@echo "... tests/bla.s"
	@echo "... tests/graphicalTest/test.o"
	@echo "... tests/graphicalTest/test.i"
	@echo "... tests/graphicalTest/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

