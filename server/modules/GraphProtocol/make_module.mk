GI_PI_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

GI_PI		=	$(SRC_FOLDER)graph_PI.c		\
			$(SRC_FOLDER)graph_for_each.c

############################################################

INCPATH		+=	$(addprefix $(GI_PI_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(GI_PI_DIR), $(GI_PI))
