NAME		=	zappy_server

# Directories

ROOT		=	../

LDPATH		=	$(ROOT)libs/
LOCAL		=	src/
COMMON		=	$(ROOT)common/src/

INC_FOLDER	=	inc/
SRC_FOLDER	=	src/

INCPATH		=	inc/			\
			$(LDPATH)list/inc/	\
			$(ROOT)common/inc/

MODDIR		=	./modules/

# Modules

MODULE_DIRS	=	$(MODDIR)AIProtocol	\
			$(MODDIR)Event		\
			$(MODDIR)Egg		\
			$(MODDIR)Graphic	\
			$(MODDIR)GraphProtocol	\
			$(MODDIR)Network	\
			$(MODDIR)Parameters	\
			$(MODDIR)Player		\
			$(MODDIR)Team		\
			$(MODDIR)Vector		\
			$(MODDIR)World


MODULES		=	$(addsuffix /make_module.mk, $(MODULE_DIRS))

# Sources

SRC		=	$(COMMON)print_error.c		\
			$(COMMON)print_warning.c	\
			$(COMMON)print_log.c		\
			$(COMMON)print_debug.c		\
			$(LOCAL)gs_get_map_height.c	\
			$(LOCAL)gs_get_map_size.c	\
			$(LOCAL)gs_get_map_width.c	\
			$(LOCAL)gs_time_update.c	\
			$(LOCAL)main.c

include $(MODULES)

OBJ		=	$(SRC:.c=.o)
LIBNAMES	=	list

LIBS		=	$(addprefix $(LDPATH), $(LIBNAMES))

# Debug

DEBUG		?=	false

ifneq		($(DEBUG), false)
CFLAGS		+=	-DDEBUG
CFLAGS		+=	-g3
else
CFLAGS		+=	-O3 -funroll-loops
endif

# Binary tools

CC		=	gcc
CP		=	cp
RM		=	rm -f

PRINTF		?=	/usr/bin/printf
CHECK		=	$(ROOT)/tools/norme.py

# Flags

CFLAGS		+=	-Wall -Wextra -Werror		\
			-Wnonnull			\
			$(addprefix -I, $(INCPATH))

LDFLAGS		+=	$(addprefix -L, $(LIBS))	\
			$(addprefix -l, $(LIBNAMES))	\
			-lm

# Rules

$(NAME)		:	$(OBJ)
			@ $(PRINTF) "\nCompiled with $(CC) and following flags:\t\033[34m$(CFLAGS)\033[m\n"
			@ $(PRINTF) "Linked with following libraries:\t\033[34m$(LDFLAGS)\033[m\n"
			@ $(PRINTF) "Binary name is: \033[36m $@\033[m\n"
			@ $(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)

all		:	$(NAME)

clean		:
			@ $(PRINTF) "\033[36mRemoved all object files.\033[m\n"
			@ $(RM) $(OBJ)

fclean		:	clean
			@ $(PRINTF) "\033[36mRemoved binaries.\033[m\n"
			@ $(RM) $(NAME)

re		:	fclean all

check		:
			@ $(CHECK) ./ -nocheat -score -printline -return -noheader -malloc -makefile

%.o		:	%.c
			@ $(CC) $(CFLAGS) -o $@ -c $<
			@ $(PRINTF) "\033[32m[OK]\033[m --> $< \n"

.PHONY		:	all clean fclean re make_libs check

.SUFFIXES	:	%.c
