##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

include ../../common/depend.mk

OUTPATH		=	../..

INCLUDES	=	-I$(OUTPATH)/libs/Json/includes		\
			-I$(OUTPATH)/libs/SmartEvent/includes	\
			-I$(OUTPATH)/srcs			\
			-I$(OUTPATH)/srcs/ECS/Entity		\
			-I$(OUTPATH)/srcs/ECS/Component		\
			-I$(OUTPATH)/srcs/Graphical		\

SRCS		=	Main.cpp	        		\
			$(OUTPATH)/srcs/ECS/Entity/Entity.cpp   \

OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	bomberman

EXTERNLIBS	=	-L$(OUTPATH)/libs/Json -lstatic_Json -L$(OUTPATH)/libs/SmartEvent -lstatic_SmartEvent -lIrrlicht -lGL

all		:	makelibs $(NAME)

makelibs	:
			make -C $(OUTPATH)/libs/Json includes && make -C $(OUTPATH)/libs/Json
			make -C $(OUTPATH)/libs/SmartEvent includes && make -C $(OUTPATH)/libs/SmartEvent

$(NAME)		:
			$(CPP) -o $(NAME) $(CPPFLAGS) $(INCLUDES) $(SRCS) $(EXTERNLIBS)

$(ODIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

$(REALODIR)/%.o	:	$(REALSDIR)/%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

clean		:
			make -C $(OUTPATH)/libs/Json clean
			make -C $(OUTPATH)/libs/SmartEvent clean
			rm -rf $(ODIR)

fclean		:	clean
			make -C $(OUTPATH)/libs/Json fclean
			make -C $(OUTPATH)/libs/SmartEvent fclean
			rm -f $(NAME)

re		:	fclean all
