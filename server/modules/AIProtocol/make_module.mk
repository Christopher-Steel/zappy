AI_PI_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

AI_PI		=	$(SRC_FOLDER)AI_PI.c	\
			$(SRC_FOLDER)AI_PO.c

############################################################

INCPATH		+=	$(addprefix $(AI_PI_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(AI_PI_DIR), $(AI_PI))
