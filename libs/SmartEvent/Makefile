## ---------------------------------------------------------------------------
## "THE BEER-WARE LICENSE" (Revision 42):
## <benjamin.viguier@epitech.eu> wrote this file. As long as you retain this 
## notice you can do whatever you want with this stuff. If we meet some day,
## and you think this stuff is worth it, you can buy me a beer in
## return Benjamin Viguier
## ---------------------------------------------------------------------------

include ./common/depend.mk

INCLUDES	+=	$(addprefix -I $(SDIR)/,	\
				Event			\
				HdlCollector	\
				Manager		\
			)

CPPFLAGS	+=	-fPIC

MKINCLUDE	=	Event.hpp		\
			Event.tpp		\
			HdlCollector.hpp	\
			Manager.hpp		\
			Manager.tpp

OUTINCLUDE	=	$(addprefix includes/SmartEvent/, $(MKINCLUDE))

SRCS		=	Event/Event.cpp			\
			HdlCollector/HdlCollector.cpp

OBJS		=	$(addprefix $(ODIR)/, $(SRCS:.cpp=.o))

NAME		=	SmartEvent

SH_NAME		=	$(OUTPATH)/lib$(NAME).so
ST_NAME		=	$(OUTPATH)/libstatic_$(NAME).a

all		:	$(NAME)

includes/SmartEvent/%.hpp	:	$(SDIR)/**/%.hpp
					@printf $(BLUE)"Creating $@\n"$(DEFAULT)
					@mkdir -p $(dir $@)
					@cp $< $@

includes/SmartEvent/%.tpp	:	$(SDIR)/**/%.tpp
					@printf $(BLUE)"Creating $@\n"$(DEFAULT)
					@mkdir -p $(dir $@)
					@cp $< $@

includes	:	$(OUTINCLUDE)

static		:	$(OBJS)
			$(AR) $(ST_NAME) $(OBJS)
			ranlib $(ST_NAME)

shared		:	$(OBJS)
			$(CPP) -shared -o $(SH_NAME) $(OBJS)

$(NAME)		:	shared static

$(ODIR)/%.o	:	$(SDIR)/%.cpp
			@mkdir -p $(dir $@)
			$(CPP) $(CPPFLAGS) $(INCLUDES)	-c -o $@ $<

clean		:
			rm -rf $(ODIR)

fclean		:	clean
			rm -f $(SH_NAME) $(ST_NAME)
			rm -r includes

re		:	fclean all