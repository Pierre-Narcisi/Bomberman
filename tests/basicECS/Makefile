##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

include ../../common/depend.mk

OUTPATH		=	../..

INCLUDES	=	-I$(OUTPATH)/libs/Json/includes		\
			-I$(OUTPATH)/libs/Json/srcs/		\
			-I$(OUTPATH)/libs/SmartEvent/includes	\
			-I$(OUTPATH)/srcs			\
			-I$(OUTPATH)/srcs/ECS/Entity		\
			-I$(OUTPATH)/srcs/ECS/Component		\

SRCS		=	Main.cpp			\
			$(OUTPATH)/srcs/ECS/Entity/Entity.cpp

OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	bomberman

EXTERNLIBS	=	-L$(OUTPATH)/libs/Json -lstatic_Json -L$(OUTPATH)/libs/SmartEvent -lstatic_SmartEvent

all		:	$(NAME)

$(NAME)		:
			$(CPP) -v -o $(NAME) $(CPPFLAGS) $(INCLUDES) $(SRCS) $(EXTERNLIBS)

$(ODIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

$(REALODIR)/%.o	:	$(REALSDIR)/%.cpp
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