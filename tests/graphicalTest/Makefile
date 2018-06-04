##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

include ../../common/depend.mk

OUTPATH		=	../..

INCLUDES	=	-I$(OUTPATH)/libs/Json/includes			\
			-I$(OUTPATH)/srcs				\

SRCS		=	test.cpp					\
			$(OUTPATH)/srcs/ECS/Entity/Entity.cpp		\
			$(OUTPATH)/srcs/Settings/Inputs.cpp		\
			$(OUTPATH)/srcs/Settings/Settings.cpp		\
			$(OUTPATH)/srcs/Graphical/EventReceiver.cpp	\
			$(OUTPATH)/srcs/Game/Game.cpp			\
			$(OUTPATH)/srcs/MapGen/mapGen.cpp		\
			$(OUTPATH)/srcs/System/Create.cpp		\
			$(OUTPATH)/srcs/System/Being.cpp		\
			$(OUTPATH)/srcs/System/EventManager.cpp		\
			$(OUTPATH)/srcs/System/UpdateDeplacement.cpp	\

OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	bomberman

EXTERNLIBS	=	-L$(OUTPATH)/libs/Json -lstatic_Json -lIrrlicht -lGL

all		:	makelibs $(NAME)

makelibs	:
			make -C $(OUTPATH)/libs/Json includes && make -C $(OUTPATH)/libs/Json

$(NAME)		:	$(OBJS)
			$(CPP) -o $(NAME) $(CPPFLAGS) $(INCLUDES) $(OBJS) $(EXTERNLIBS)

$(ODIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

clean		:
			make -C $(OUTPATH)/libs/Json clean
			rm -rf $(OBJS)
			rm -rf $(ODIR)

fclean		:	clean
			make -C $(OUTPATH)/libs/Json fclean
			rm -f $(NAME)

re		:	fclean all
