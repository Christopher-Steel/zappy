TEAM_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

TEAM		=	$(SRC_FOLDER)team.c			\
			$(SRC_FOLDER)team_add_player.c		\
			$(SRC_FOLDER)team_create_player.c	\
			$(SRC_FOLDER)team_update_max_level.c

############################################################

INCPATH		+=	$(addprefix $(TEAM_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(TEAM_DIR), $(TEAM))
