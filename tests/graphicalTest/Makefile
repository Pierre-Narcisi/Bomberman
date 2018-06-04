##
## EPITECH PROJECT, 2017
## Client
## File description:
## Makefile
##

include ../../common/depend.mk

OUTPATH		=	../..

INCLUDES	=	-I$(OUTPATH)/libs/Json/includes		\
			-I$(OUTPATH)/libs/Json/srcs/Entity      \
			-I$(OUTPATH)/libs/SmartEvent/includes	\
			-I$(OUTPATH)/libs/SmartEvent/srcs	\
			-I$(OUTPATH)/libs/SmartEvent/srcs/Manager	\
			-I$(OUTPATH)/srcs			\
			-I$(OUTPATH)/srcs/Graphical		\
			-I$(OUTPATH)/srcs/ECS/Entity		\
			-I$(OUTPATH)/srcs/ECS/Component		\
			-I$(OUTPATH)/tests      		\
			-I$(OUTPATH)/srcs/Component             \
			-I$(OUTPATH)/srcs/Systems


SRCS		=	test.cpp	        		\
			$(OUTPATH)/srcs/ECS/Entity/Entity.cpp   \
			$(OUTPATH)/srcs/Graphical/*.cpp	\
			$(OUTPATH)/srcs/MapGen/mapGen.cpp       \
			$(OUTPATH)/srcs/Systems/SystemCreate.cpp

OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	bomberman

EXTERNLIBS	=	-L$(OUTPATH)/libs/Json -lstatic_Json -L$(OUTPATH)/libs/SmartEvent -lstatic_SmartEvent -lIrrlicht -lGL

all		:	$(NAME)

$(NAME)		:
			$(CPP) -g -o $(NAME) $(CPPFLAGS) $(INCLUDES) $(SRCS) $(EXTERNLIBS)

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
