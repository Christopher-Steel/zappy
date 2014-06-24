SERVER_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

SERVER		=	$(SRC_FOLDER)gs_get_map_height.c	\
			$(SRC_FOLDER)gs_get_map_size.c		\
			$(SRC_FOLDER)gs_get_map_width.c

############################################################

INCPATH		+=	$(addprefix $(SERVER_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(SERVER_DIR), $(SERVER))
