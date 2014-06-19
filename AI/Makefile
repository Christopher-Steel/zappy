NAME		=	zappy_AI

LOCAL		=	src/

SRC		=	$(LOCAL)test.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -pedantic

LDFLAGS		=

$(NAME)		:	$(OBJ)
			@ $(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all		:	$(NAME)

clean		:
			@ $(RM) $(OBJ)

fclean		:	clean
			@ $(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
