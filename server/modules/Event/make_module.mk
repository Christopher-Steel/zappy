EVENT_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

EVENT		=	$(SRC_FOLDER)event.c		\
			$(SRC_FOLDER)event_ordered.c

############################################################

INCPATH		+=	$(addprefix $(EVENT_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(EVENT_DIR), $(EVENT))
