PLAYER_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

PLAYER		=	$(SRC_FOLDER)player_avance.c		\
			$(SRC_FOLDER)player_broadcast.c		\
			$(SRC_FOLDER)player_connect_nbr.c	\
			$(SRC_FOLDER)player_droite.c		\
			$(SRC_FOLDER)player_expulse.c		\
			$(SRC_FOLDER)player_fork.c		\
			$(SRC_FOLDER)player_gauche.c		\
			$(SRC_FOLDER)player_inventaire.c	\
			$(SRC_FOLDER)player_incantation.c	\
			$(SRC_FOLDER)player_pose_prend.c	\
			$(SRC_FOLDER)player_voir.c		\
			\
			$(SRC_FOLDER)player_life_update.c	\
			$(SRC_FOLDER)create_player.c		\
			$(SRC_FOLDER)get_vision_point.c		\
			$(SRC_FOLDER)send_view.c		\
			$(SRC_FOLDER)size_str_view.c		\
			$(SRC_FOLDER)stop_elevation.c		\
			$(SRC_FOLDER)get_vec_direction.c


############################################################

INCPATH		+=	$(addprefix $(PLAYER_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(PLAYER_DIR), $(PLAYER))
