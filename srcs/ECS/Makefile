##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

CPP		=	g++

WALL		=	-W -Wall -Wextra

OPTI		=	-O2

DEBUG		=	-g

INCLUDES	=	-I ./Entity	\
			-I ./Component	\

CPPFLAGS	=	$(WALL) $(OPTI) $(DEBUG) $(INCLUDES)

SRCS		=	Entity/Entity.cpp	\
			Entity/Manager.cpp	\
			main.cpp

all:
	$(CPP) $(INCLUDES) $(SRCS)
