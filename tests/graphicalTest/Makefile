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
			-I$(OUTPATH)/srcs			\
			-I$(OUTPATH)/srcs/ECS		\
			-I$(OUTPATH)/srcs/ECS/Component		\
			-I$(OUTPATH)/tests      		\

SRCS		=	test.cpp	        		\
			$(OUTPATH)/srcs/ECS/Entity/Entity.cpp   \
			$(OUTPATH)/srcs/Graphical/*.cpp

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
