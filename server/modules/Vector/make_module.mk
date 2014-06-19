VECTOR_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

############################################################

INCPATH		+=	$(addprefix $(VECTOR_DIR), $(INC_FOLDER))
