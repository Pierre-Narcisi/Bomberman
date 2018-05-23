## ---------------------------------------------------------------------------
## "THE BEER-WARE LICENSE" (Revision 42):
## <benjamin.viguier@epitech.eu> wrote this file. As long as you retain this 
## notice you can do whatever you want with this stuff. If we meet some day,
## and you think this stuff is worth it, you can buy me a beer in
## return Benjamin Viguier
## ---------------------------------------------------------------------------

include ./common/depend.mk

INCLUDES	+=	$(addprefix -I $(SDIR)/,	\
				./			\
			)

MKINCLUDE	=	Parser.hpp	\
			JsonEntity.hpp

OUTINCLUDE	=	$(addprefix includes/, $(MKINCLUDE))

CPPFLAGS	+=	-fPIC

SRCS		=	Parser/Parser.cpp	\
			Entity/Entity.cpp
OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	Json

SH_NAME		=	$(OUTPATH)/lib$(NAME).so
ST_NAME		=	$(OUTPATH)/libstatic_$(NAME).a

all		:	$(NAME)

includes/%.hpp	:	$(SDIR)/**/%.hpp
			@printf $(BLUE)"Creating $@\n"$(DEFAULT)
			@mkdir -p $(dir $@)
			@cp $< $@

includes	:	$(OUTINCLUDE)

static		:	$(ST_NAME)

shared		:	$(SH_NAME)

$(NAME)		:	$(SH_NAME) $(ST_NAME)

$(SH_NAME)	:	$(OBJS)
			$(CPP) -shared -o $(SH_NAME) $(OBJS)

$(ST_NAME)	:	$(OBJS)
			$(AR) $(ST_NAME) $(OBJS)
			ranlib $(ST_NAME)

$(ODIR)/%.o	:	$(SDIR)/%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

clean		:
			rm -rf $(ODIR)

fclean		:	clean
			rm -f $(SH_NAME) $(ST_NAME)
			rm -rf ./includes

re		:	fclean all