M_DIR		:=	$(dir $(lastword $(MAKEFILE_LIST)))

M_SRCDIR	=	src/

############################################################

M_SRC		=	$(M_SRCDIR)test.c		\

############################################################

SRC		+=	$(addprefix $(M_DIR), $(M_SRC))
