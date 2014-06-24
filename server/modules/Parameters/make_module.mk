PARAMETERS_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

PARAMETERS	=	$(SRC_FOLDER)parse_parameter.c		\
			$(SRC_FOLDER)print_usage.c		\
			$(SRC_FOLDER)set_numeric_parameter.c	\
			$(SRC_FOLDER)set_team_name.c

############################################################

INCPATH		+=	$(addprefix $(PARAMETERS_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(PARAMETERS_DIR), $(PARAMETERS))
