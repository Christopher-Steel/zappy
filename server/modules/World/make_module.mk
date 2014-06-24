WORLD_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

WORLD		=	$(SRC_FOLDER)generate_world.c		\
			$(SRC_FOLDER)spawn_ressource.c

############################################################

INCPATH		+=	$(addprefix $(WORLD_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(WORLD_DIR), $(WORLD))
