PLAYER_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

PLAYER		=	$(SRC_FOLDER)create_player.c		\
			$(SRC_FOLDER)move_forward.c		\
			$(SRC_FOLDER)move_left.c		\
			$(SRC_FOLDER)move_right.c		\
			$(SRC_FOLDER)set_orientation.c		\
			$(SRC_FOLDER)show_inventory.c		\
			$(SRC_FOLDER)show_list_player.c		\
			$(SRC_FOLDER)take_or_put_object.c

############################################################

INCPATH		+=	$(addprefix $(PLAYER_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(PLAYER_DIR), $(PLAYER))
