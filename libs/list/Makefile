##
## Makefile for List in /home/mougen_v/rendus/PSU_2013_zappy/libs/list
##
## Made by Valentin
## Login   <mougen_v@epitech.net>
##
## Started on  Sun Jul 13 18:01:08 2014 Valentin
## Last update Sun Jul 13 18:01:09 2014 Valentin
##

NAME		=	liblist.a

ROOT		=	../../

LOCAL		=	src/

INC		=	inc/				\
			$(ROOT)common/inc/

SRC		=	$(LOCAL)create_destroy_list.c	\
			$(LOCAL)create_destroy_node.c	\
			$(LOCAL)insert_after.c		\
			$(LOCAL)insert_remove.c		\
			$(LOCAL)push_pop_front.c	\
			$(LOCAL)push_back.c		\
			$(LOCAL)front_begin.c		\
			$(LOCAL)size.c			\
			$(LOCAL)empty.c			\
			$(LOCAL)list_clear.c		\
			$(LOCAL)for_each.c		\
			$(LOCAL)filter.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -pedantic	\
			$(addprefix -I, $(INC))

ifneq		($(DEBUG), false)
CFLAGS		+=	-ggdb
endif

LDFLAGS		=

$(NAME)		:	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
