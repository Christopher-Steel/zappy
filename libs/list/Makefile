NAME		=	liblist.a

ROOT		=	../../

LOCAL		=	src/

INC		=	inc/				\
			$(ROOT)common/inc/

SRC		=	$(LOCAL)create_destroy_list.c	\
			$(LOCAL)create_destroy_node.c	\
			$(LOCAL)insert_remove.c		\
			$(LOCAL)push_pop_front.c	\
			$(LOCAL)push_back.c		\
			$(LOCAL)front_begin.c		\
			$(LOCAL)size.c			\
			$(LOCAL)for_each.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -pedantic	\
			$(addprefix -I, $(INC))

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
