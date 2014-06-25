WORLD_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

WORLD		=	$(SRC_FOLDER)generate_world.c		\
			$(SRC_FOLDER)spawn_ressource.c		\
			$(SRC_FOLDER)add_player.c		\
			$(SRC_FOLDER)remove_player.c		\
			$(SRC_FOLDER)spawn_player.c		\
			# $(SRC_FOLDER)list_world.c

############################################################

INCPATH		+=	$(addprefix $(WORLD_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(WORLD_DIR), $(WORLD))
