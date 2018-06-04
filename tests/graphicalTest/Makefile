##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

include ../../common/depend.mk

OUTPATH		=	../..

INCLUDES	=	-I$(OUTPATH)/srcs				\
			-I$(OUTPATH)/libs                               \
                        -I$(OUTPATH)/libs/Json/srcs                     \
                        -I$(OUTPATH)/libs/Json/srcs/Entity              \
                        -I$(OUTPATH)/libs/Json/srcs/Parser              \
                        -I$(OUTPATH)/libs/Json/tests/Parser/srcs/Entity \
                        -I$(OUTPATH)/libs/Json/tests/Parser/srcs/Parser \
                        -I$(OUTPATH)/libs/SmartEvent/srcs               \
                        -I$(OUTPATH)/libs/SmartEvent/srcs/Event         \
                        -I$(OUTPATH)/libs/SmartEvent/srcs/HdlCollector  \
                        -I$(OUTPATH)/libs/SmartEvent/srcs/Manager       \
                        -I$(OUTPATH)/srcs                               \
                        -I$(OUTPATH)/srcs/Component                     \
                        -I$(OUTPATH)/srcs/Console                       \
                        -I$(OUTPATH)/srcs/ECS/Component                 \
                        -I$(OUTPATH)/srcs/ECS/Entity                    \
                        -I$(OUTPATH)/srcs/Game                          \
                        -I$(OUTPATH)/srcs/Graphical                     \
                        -I$(OUTPATH)/srcs/MapGen                        \
                        -I$(OUTPATH)/srcs/Settings                      \
                        -I$(OUTPATH)/srcs/System                        \
                        -I$(OUTPATH)/srcs/Systems                       \
                        -I$(OUTPATH)/tests/basicECS                     \

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
