GRAPHIC_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

##########################################################################

GRAPHIC		=	$(SRC_FOLDER)graphic_manager_init.c	\
			$(SRC_FOLDER)graphic_manager_shutdown.c	\
			$(SRC_FOLDER)graphic_create.c		\
			\
			$(SRC_FOLDER)graphic_bct.c		\
			$(SRC_FOLDER)graphic_egg_action.c	\
			$(SRC_FOLDER)graphic_invalid_cmd.c	\
			$(SRC_FOLDER)graphic_mct.c		\
			$(SRC_FOLDER)graphic_msz.c		\
			$(SRC_FOLDER)graphic_player_action.c	\
			$(SRC_FOLDER)graphic_player_get_put.c	\
			$(SRC_FOLDER)graphic_player_info.c	\
			$(SRC_FOLDER)graphic_pnw.c		\
			$(SRC_FOLDER)graphic_server_info.c	\
			$(SRC_FOLDER)graphic_time.c		\
			$(SRC_FOLDER)graphic_tna.c		\
			\
			$(SRC_FOLDER)graphic_ppo_bct_pin_2.c

##########################################################################

INCPATH		+=	$(addprefix $(GRAPHIC_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(GRAPHIC_DIR), $(GRAPHIC))
