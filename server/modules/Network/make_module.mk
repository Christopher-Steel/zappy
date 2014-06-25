AI_PI_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

SOCKET		=	$(SRC_FOLDER)tcp_socket/
RING_BUFFER	=	$(SRC_FOLDER)ring_buffer/

############################################################

AI_PI		=	$(SOCKET)tcp_sock_create.c		\
			$(SOCKET)tcp_sock_get_addr.c		\
			$(SOCKET)tcp_sock_init.c		\
			\
			$(RING_BUFFER)ring_buf_create.c		\
			$(RING_BUFFER)ring_buf_ctor.c		\
			$(RING_BUFFER)ring_buf_len.c		\
			$(RING_BUFFER)ring_buf_push.c		\
			$(RING_BUFFER)ring_buf_pop.c		\
			$(RING_BUFFER)ring_buf_read.c		\
			$(RING_BUFFER)ring_buf_write.c

############################################################

INCPATH		+=	$(addprefix $(AI_PI_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(AI_PI_DIR), $(AI_PI))
