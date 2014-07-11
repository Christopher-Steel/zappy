EGG_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

EGG		=	$(SRC_FOLDER)egg_create_destroy.c	\
			$(SRC_FOLDER)egg_hatch.c		\
			$(SRC_FOLDER)egg_event_handler.c

############################################################

INCPATH		+=	$(addprefix $(EGG_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(EGG_DIR), $(EGG))
