VECTOR_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

VECTOR		=	$(SRC_FOLDER)add_vector.c	\
			$(SRC_FOLDER)equal_vector.c	\
			$(SRC_FOLDER)sub_vector.c

############################################################

INCPATH		+=	$(addprefix $(VECTOR_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(VECTOR_DIR), $(VECTOR))
