NAME		=	liblist.a

LOCAL		=	src/

SRC		=	$(LOCAL)test.c

OBJ		=	$(SRC:.c=.o)

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
