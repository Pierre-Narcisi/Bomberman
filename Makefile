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
# Target rules for targets named Bomberman

# Build rule for target.
Bomberman: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Bomberman
.PHONY : Bomberman

# fast build rule for target.
Bomberman/fast:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/build
.PHONY : Bomberman/fast

srcs/Console/Console.o: srcs/Console/Console.cpp.o

.PHONY : srcs/Console/Console.o

# target to build an object file
srcs/Console/Console.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Console/Console.cpp.o
.PHONY : srcs/Console/Console.cpp.o

srcs/Console/Console.i: srcs/Console/Console.cpp.i

.PHONY : srcs/Console/Console.i

# target to preprocess a source file
srcs/Console/Console.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Console/Console.cpp.i
.PHONY : srcs/Console/Console.cpp.i

srcs/Console/Console.s: srcs/Console/Console.cpp.s

.PHONY : srcs/Console/Console.s

# target to generate assembly for a file
srcs/Console/Console.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Console/Console.cpp.s
.PHONY : srcs/Console/Console.cpp.s

srcs/ECS/Entity/Entity.o: srcs/ECS/Entity/Entity.cpp.o

.PHONY : srcs/ECS/Entity/Entity.o

# target to build an object file
srcs/ECS/Entity/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/ECS/Entity/Entity.cpp.o
.PHONY : srcs/ECS/Entity/Entity.cpp.o

srcs/ECS/Entity/Entity.i: srcs/ECS/Entity/Entity.cpp.i

.PHONY : srcs/ECS/Entity/Entity.i

# target to preprocess a source file
srcs/ECS/Entity/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/ECS/Entity/Entity.cpp.i
.PHONY : srcs/ECS/Entity/Entity.cpp.i

srcs/ECS/Entity/Entity.s: srcs/ECS/Entity/Entity.cpp.s

.PHONY : srcs/ECS/Entity/Entity.s

# target to generate assembly for a file
srcs/ECS/Entity/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/ECS/Entity/Entity.cpp.s
.PHONY : srcs/ECS/Entity/Entity.cpp.s

srcs/Game/Game.o: srcs/Game/Game.cpp.o

.PHONY : srcs/Game/Game.o

# target to build an object file
srcs/Game/Game.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Game/Game.cpp.o
.PHONY : srcs/Game/Game.cpp.o

srcs/Game/Game.i: srcs/Game/Game.cpp.i

.PHONY : srcs/Game/Game.i

# target to preprocess a source file
srcs/Game/Game.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Game/Game.cpp.i
.PHONY : srcs/Game/Game.cpp.i

srcs/Game/Game.s: srcs/Game/Game.cpp.s

.PHONY : srcs/Game/Game.s

# target to generate assembly for a file
srcs/Game/Game.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Game/Game.cpp.s
.PHONY : srcs/Game/Game.cpp.s

srcs/Graphical/EventReceiver.o: srcs/Graphical/EventReceiver.cpp.o

.PHONY : srcs/Graphical/EventReceiver.o

# target to build an object file
srcs/Graphical/EventReceiver.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Graphical/EventReceiver.cpp.o
.PHONY : srcs/Graphical/EventReceiver.cpp.o

srcs/Graphical/EventReceiver.i: srcs/Graphical/EventReceiver.cpp.i

.PHONY : srcs/Graphical/EventReceiver.i

# target to preprocess a source file
srcs/Graphical/EventReceiver.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Graphical/EventReceiver.cpp.i
.PHONY : srcs/Graphical/EventReceiver.cpp.i

srcs/Graphical/EventReceiver.s: srcs/Graphical/EventReceiver.cpp.s

.PHONY : srcs/Graphical/EventReceiver.s

# target to generate assembly for a file
srcs/Graphical/EventReceiver.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Graphical/EventReceiver.cpp.s
.PHONY : srcs/Graphical/EventReceiver.cpp.s

srcs/MapGen/mapGen.o: srcs/MapGen/mapGen.cpp.o

.PHONY : srcs/MapGen/mapGen.o

# target to build an object file
srcs/MapGen/mapGen.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/MapGen/mapGen.cpp.o
.PHONY : srcs/MapGen/mapGen.cpp.o

srcs/MapGen/mapGen.i: srcs/MapGen/mapGen.cpp.i

.PHONY : srcs/MapGen/mapGen.i

# target to preprocess a source file
srcs/MapGen/mapGen.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/MapGen/mapGen.cpp.i
.PHONY : srcs/MapGen/mapGen.cpp.i

srcs/MapGen/mapGen.s: srcs/MapGen/mapGen.cpp.s

.PHONY : srcs/MapGen/mapGen.s

# target to generate assembly for a file
srcs/MapGen/mapGen.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/MapGen/mapGen.cpp.s
.PHONY : srcs/MapGen/mapGen.cpp.s

srcs/Settings/Inputs.o: srcs/Settings/Inputs.cpp.o

.PHONY : srcs/Settings/Inputs.o

# target to build an object file
srcs/Settings/Inputs.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Settings/Inputs.cpp.o
.PHONY : srcs/Settings/Inputs.cpp.o

srcs/Settings/Inputs.i: srcs/Settings/Inputs.cpp.i

.PHONY : srcs/Settings/Inputs.i

# target to preprocess a source file
srcs/Settings/Inputs.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Settings/Inputs.cpp.i
.PHONY : srcs/Settings/Inputs.cpp.i

srcs/Settings/Inputs.s: srcs/Settings/Inputs.cpp.s

.PHONY : srcs/Settings/Inputs.s

# target to generate assembly for a file
srcs/Settings/Inputs.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Settings/Inputs.cpp.s
.PHONY : srcs/Settings/Inputs.cpp.s

srcs/Settings/Settings.o: srcs/Settings/Settings.cpp.o

.PHONY : srcs/Settings/Settings.o

# target to build an object file
srcs/Settings/Settings.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Settings/Settings.cpp.o
.PHONY : srcs/Settings/Settings.cpp.o

srcs/Settings/Settings.i: srcs/Settings/Settings.cpp.i

.PHONY : srcs/Settings/Settings.i

# target to preprocess a source file
srcs/Settings/Settings.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Settings/Settings.cpp.i
.PHONY : srcs/Settings/Settings.cpp.i

srcs/Settings/Settings.s: srcs/Settings/Settings.cpp.s

.PHONY : srcs/Settings/Settings.s

# target to generate assembly for a file
srcs/Settings/Settings.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/Settings/Settings.cpp.s
.PHONY : srcs/Settings/Settings.cpp.s

srcs/System/Ai.o: srcs/System/Ai.cpp.o

.PHONY : srcs/System/Ai.o

# target to build an object file
srcs/System/Ai.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Ai.cpp.o
.PHONY : srcs/System/Ai.cpp.o

srcs/System/Ai.i: srcs/System/Ai.cpp.i

.PHONY : srcs/System/Ai.i

# target to preprocess a source file
srcs/System/Ai.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Ai.cpp.i
.PHONY : srcs/System/Ai.cpp.i

srcs/System/Ai.s: srcs/System/Ai.cpp.s

.PHONY : srcs/System/Ai.s

# target to generate assembly for a file
srcs/System/Ai.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Ai.cpp.s
.PHONY : srcs/System/Ai.cpp.s

srcs/System/Being.o: srcs/System/Being.cpp.o

.PHONY : srcs/System/Being.o

# target to build an object file
srcs/System/Being.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Being.cpp.o
.PHONY : srcs/System/Being.cpp.o

srcs/System/Being.i: srcs/System/Being.cpp.i

.PHONY : srcs/System/Being.i

# target to preprocess a source file
srcs/System/Being.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Being.cpp.i
.PHONY : srcs/System/Being.cpp.i

srcs/System/Being.s: srcs/System/Being.cpp.s

.PHONY : srcs/System/Being.s

# target to generate assembly for a file
srcs/System/Being.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Being.cpp.s
.PHONY : srcs/System/Being.cpp.s

srcs/System/Create.o: srcs/System/Create.cpp.o

.PHONY : srcs/System/Create.o

# target to build an object file
srcs/System/Create.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Create.cpp.o
.PHONY : srcs/System/Create.cpp.o

srcs/System/Create.i: srcs/System/Create.cpp.i

.PHONY : srcs/System/Create.i

# target to preprocess a source file
srcs/System/Create.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Create.cpp.i
.PHONY : srcs/System/Create.cpp.i

srcs/System/Create.s: srcs/System/Create.cpp.s

.PHONY : srcs/System/Create.s

# target to generate assembly for a file
srcs/System/Create.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/Create.cpp.s
.PHONY : srcs/System/Create.cpp.s

srcs/System/EventManager.o: srcs/System/EventManager.cpp.o

.PHONY : srcs/System/EventManager.o

# target to build an object file
srcs/System/EventManager.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/EventManager.cpp.o
.PHONY : srcs/System/EventManager.cpp.o

srcs/System/EventManager.i: srcs/System/EventManager.cpp.i

.PHONY : srcs/System/EventManager.i

# target to preprocess a source file
srcs/System/EventManager.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/EventManager.cpp.i
.PHONY : srcs/System/EventManager.cpp.i

srcs/System/EventManager.s: srcs/System/EventManager.cpp.s

.PHONY : srcs/System/EventManager.s

# target to generate assembly for a file
srcs/System/EventManager.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/EventManager.cpp.s
.PHONY : srcs/System/EventManager.cpp.s

srcs/System/UpdateDeplacement.o: srcs/System/UpdateDeplacement.cpp.o

.PHONY : srcs/System/UpdateDeplacement.o

# target to build an object file
srcs/System/UpdateDeplacement.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/UpdateDeplacement.cpp.o
.PHONY : srcs/System/UpdateDeplacement.cpp.o

srcs/System/UpdateDeplacement.i: srcs/System/UpdateDeplacement.cpp.i

.PHONY : srcs/System/UpdateDeplacement.i

# target to preprocess a source file
srcs/System/UpdateDeplacement.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/UpdateDeplacement.cpp.i
.PHONY : srcs/System/UpdateDeplacement.cpp.i

srcs/System/UpdateDeplacement.s: srcs/System/UpdateDeplacement.cpp.s

.PHONY : srcs/System/UpdateDeplacement.s

# target to generate assembly for a file
srcs/System/UpdateDeplacement.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/srcs/System/UpdateDeplacement.cpp.s
.PHONY : srcs/System/UpdateDeplacement.cpp.s

tests/graphicalTest/test.o: tests/graphicalTest/test.cpp.o

.PHONY : tests/graphicalTest/test.o

# target to build an object file
tests/graphicalTest/test.cpp.o:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/tests/graphicalTest/test.cpp.o
.PHONY : tests/graphicalTest/test.cpp.o

tests/graphicalTest/test.i: tests/graphicalTest/test.cpp.i

.PHONY : tests/graphicalTest/test.i

# target to preprocess a source file
tests/graphicalTest/test.cpp.i:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/tests/graphicalTest/test.cpp.i
.PHONY : tests/graphicalTest/test.cpp.i

tests/graphicalTest/test.s: tests/graphicalTest/test.cpp.s

.PHONY : tests/graphicalTest/test.s

# target to generate assembly for a file
tests/graphicalTest/test.cpp.s:
	$(MAKE) -f CMakeFiles/Bomberman.dir/build.make CMakeFiles/Bomberman.dir/tests/graphicalTest/test.cpp.s
.PHONY : tests/graphicalTest/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... Bomberman"
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
	@echo "... srcs/System/Ai.o"
	@echo "... srcs/System/Ai.i"
	@echo "... srcs/System/Ai.s"
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

