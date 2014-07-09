GRAPHIC_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

##########################################################################

GRAPHIC		=	$(SRC_FOLDER)graphic_manager_init.c	\
			$(SRC_FOLDER)graphic_manager_shutdown.c	\
			\
			$(SRC_FOLDER)graphic_create.c

##########################################################################

INCPATH		+=	$(addprefix $(GRAPHIC_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(GRAPHIC_DIR), $(GRAPHIC))
