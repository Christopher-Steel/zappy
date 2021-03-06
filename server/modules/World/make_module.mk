WORLD_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

ELEV_DIR	=	$(SRC_FOLDER)elevation_cond/

############################################################

WORLD		=	$(SRC_FOLDER)generate_world.c		\
			$(SRC_FOLDER)add_player.c		\
			$(SRC_FOLDER)add_egg.c			\
			$(SRC_FOLDER)remove_player.c		\
			$(SRC_FOLDER)spawn_player.c		\
			$(SRC_FOLDER)delete_player.c		\
			$(SRC_FOLDER)respawn_ressource.c	\
			$(SRC_FOLDER)victory_condition.c	\
			$(SRC_FOLDER)wrap_pos.c

############################################################

INCPATH		+=	$(addprefix $(WORLD_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(WORLD_DIR), $(WORLD))
