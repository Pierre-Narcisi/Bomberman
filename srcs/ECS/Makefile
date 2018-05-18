##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

CPP		=	g++ -std=c++17

WALL		=	-W -Wall -Wextra

OPTI		=	-O2

DEBUG		=	-g

INCLUDES	=	-I ./Entity	\
			-I ./Component	\
			-I ../../libs/Json/includes \
			-I ../../libs/SmartEvent/includes


LIBS		=	-L../../libs/Json -L../../libs/SmartEvent -lstatic_Json -lstatic_SmartEvent

CPPFLAGS	=	$(WALL) $(OPTI) $(DEBUG) $(INCLUDES)

SRCS		=	Entity/Entity.cpp	\
			main.cpp

all:
	$(CPP) $(INCLUDES) $(CPPFLAGS) $(SRCS) $(LIBS)
