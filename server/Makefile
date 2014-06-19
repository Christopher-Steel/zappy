NAME		=	zappy_server

#############################################################################
# Directories
###############################################################

ROOT		=	../

LDPATH		=	$(ROOT)libs/
LOCAL		=	./src/

INCPATH		=	./inc			\
			./$(LDPATH)list/inc

MODDIR		=	./modules/

#############################################################################
# Modules
###############################################################

MODULE_DIRS	=	$(MODDIR)Test
			# $(MODDIR)Event		\
			# $(MODDIR)Network	\
			# $(MODDIR)Player		\
			# $(MODDIR)Protocol	\
			# $(MODDIR)Startup	\
			# $(MODDIR)Time		\
			# $(MODDIR)Utils		\
			# $(MODDIR)Vector		\
			# $(MODDIR)World

MODULES		=	$(addsuffix /make_module.mk, $(MODULE_DIRS))

#############################################################################
# Sources
###############################################################

SRC		=	$(LOCAL)test.c		\

include $(MODULES)

#############################################################################

OBJ		=	$(SRC:.c=.o)
LIBNAMES	=	list

LIBS		=	$(addprefix $(LDPATH), $(LIBNAMES))

#############################################################################
# Debug
###############################################################

DEBUG		?=	false

ifneq		($(DEBUG), false)
CFLAGS		+=	-DDEBUG
CFLAGS		+=	-ggdb
endif

#############################################################################
# Binary tools
###############################################################

CC		=	gcc
CP		=	cp
RM		=	rm -f

PRINTF		?=	/usr/bin/printf
CHECK		=	$(ROOT)/tools/norme.py

#############################################################################
# Flags
###############################################################

CFLAGS		+=	-Wall -Wextra -Werror		\
			-O3 -funroll-loops		\
			$(addprefix -I, $(INCPATH))

LDFLAGS		+=	$(addprefix -L, $(LIBS))	\
			$(addprefix -l, $(LIBNAMES))	\
			-lm

#############################################################################
# Rules
###############################################################

$(NAME)		:	$(OBJ)
			@ $(PRINTF) "\nCompiled with $(CC) and following flags:\t\033[34m$(CFLAGS)\033[m\n"
			@ $(PRINTF) "Linked with following libraries:\t\033[34m$(LDFLAGS)\033[m\n"
			@ $(PRINTF) "Binary name is: \033[36m $@\033[m\n"
			@ $(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)

all		:	make_libs $(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

make_libs	:	$(LIBS)
			@ for l in $^; do unset MAKELEVEL; make -C $$l; done

check		:
			@ $(CHECK) $(LOCAL) inc/ -nocheat -score -printline -return -noheader

%.o		:	%.c
			@ $(CC) $(CFLAGS) -o $@ -c $<
			@ $(PRINTF) "\033[32m[OK]\033[m --> $< \n"

.PHONY		:	all clean fclean re make_libs check

.SUFFIXES	:	%.c
