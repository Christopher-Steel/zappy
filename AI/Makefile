NAME		=	zappy_AI

LOCAL		=	src/
INCPATH		=	inc/
RM		=	rm -f
CXX		=	g++

SRC		=	$(LOCAL)main.cpp		\
			$(LOCAL)network.cpp		\
			$(LOCAL)drone.cpp		\
			$(LOCAL)init_drone.cpp		\
			$(LOCAL)send_actions.cpp	\
			$(LOCAL)recive_actions.cpp	\
			$(LOCAL)broadcast.cpp		\
			$(LOCAL)algorithm.cpp


OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Werror		\
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
