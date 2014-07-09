GRAPHIC_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

##########################################################################

GRAPHIC		=	$(SRC_FOLDER)graphic_create.c	\
			$(SRC_FOLDER)graphic_msz.c	\
			$(SRC_FOLDER)graphic_bct.c	\
			#$(SRC_FOLDER)graphic_ .c

##########################################################################

INCPATH		+=	$(addprefix $(GRAPHIC_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(GRAPHIC_DIR), $(GRAPHIC))
