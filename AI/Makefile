NAME		=	zappy_AI

LOCAL		=	src/
INCPATH		=	inc/

SRC		=	$(LOCAL)algorithm.cpp		\
			$(LOCAL)broadcast.cpp		\
			$(LOCAL)drone.cpp		\
			$(LOCAL)init_drone.cpp		\
			$(LOCAL)main.cpp		\
			$(LOCAL)network.cpp		\
			$(LOCAL)send_actions.cpp	\
			$(LOCAL)receive_actions.cpp


OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Werror -O3		\
			$(addprefix -I, $(INCPATH))

LDFLAGS		=	-lm

$(NAME)		:	$(OBJ)
			@ $(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

all		:	$(NAME)

clean		:
			@ $(RM) $(OBJ) error* src/*~

fclean		:	clean
			@ $(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
