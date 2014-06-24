TEAM_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

TEAM		=	$(SRC_FOLDER)team.c

############################################################

INCPATH		+=	$(addprefix $(TEAM_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(TEAM_DIR), $(TEAM))
