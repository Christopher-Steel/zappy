TEST_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

############################################################

TEST		=	$(SRC_FOLDER)test.c

############################################################

INCPATH		+=	$(addprefix $(TEST_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(TEST_DIR), $(TEST))
