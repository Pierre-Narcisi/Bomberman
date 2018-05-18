##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

include ./common/depend.mk

INCLUDES	=	-Ilibs/Json/includes		\
			-Ilibs/SmartEvent/includes	\
			-Isrcs				\
			-Isrcs/ECS/Entity		\
			-Isrcs/ECS/Component		\

SRCS		=	Main.cpp			\
			ECS/Entity/Entity.cpp

OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	bomberman

EXTERNLIBS	=	-Llibs/Json -lstatic_Json -Llibs/SmartEvent -lstatic_SmartEvent

all		:	$(NAME)

$(MAKEINCLUDES)	:
			echo coucou
			make -C libs/Json includes
			make -C libs/SmartEvent includes

$(MAKELIBS)	:
			make -C libs/Json
			make -C libs/SmartEvent

$(NAME)		:	$(MAKEINCLUDES) $(OBJS) $(MAKELIBS)
			$(CPP) -o $(NAME) $(CPPFLAGS) $(INCLUDES) $(OBJS) $(EXTERNLIBS)

$(ODIR)/%.o	:	$(SDIR)/%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

clean		:
			# make -C libs/Json clean
			# make -C libs/SmartEvent clean
			rm -rf $(ODIR)

fclean		:	clean
			# make -C libs/Json fclean
			# make -C libs/SmartEvent fclean
			rm -f $(NAME)

re		:	fclean all