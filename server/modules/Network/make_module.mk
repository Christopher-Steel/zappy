NETWORK_DIR	:=	$(dir $(lastword $(MAKEFILE_LIST)))

SOCKET		=	$(SRC_FOLDER)tcp_socket/
RING_BUFFER	=	$(SRC_FOLDER)ring_buffer/
SOCKETPOOL	=	$(SRC_FOLDER)socket_pool/
INJECT_BUFFER	=	$(SRC_FOLDER)inject_buffer/
CLIENT		=	$(SRC_FOLDER)client/
HANDSHAKER	=	$(SRC_FOLDER)handshaker/

##########################################################################

NETWORK		=	$(SRC_FOLDER)network_broadcast.c		\
			$(SRC_FOLDER)network_init.c			\
			$(SRC_FOLDER)network_shutdown.c			\
			$(SRC_FOLDER)network_update.c			\
			\
			$(SOCKET)tcp_sock_create.c			\
			$(SOCKET)tcp_sock_get_addr.c			\
			$(SOCKET)tcp_sock_init.c			\
			\
			$(RING_BUFFER)ring_buf_create.c			\
			$(RING_BUFFER)ring_buf_ctor.c			\
			$(RING_BUFFER)ring_buf_len.c			\
			$(RING_BUFFER)ring_buf_empty.c			\
			$(RING_BUFFER)ring_buf_push.c			\
			$(RING_BUFFER)ring_buf_pop.c			\
			$(RING_BUFFER)ring_buf_read.c			\
			$(RING_BUFFER)ring_buf_write.c			\
			\
			$(SOCKETPOOL)sockpool_add_client.c		\
			$(SOCKETPOOL)sockpool_fill_sets.c		\
			$(SOCKETPOOL)sockpool_filter.c			\
			$(SOCKETPOOL)sockpool_handle.c			\
			$(SOCKETPOOL)sockpool_node_io.c			\
			$(SOCKETPOOL)sockpool_node_create.c		\
			$(SOCKETPOOL)sockpool_update.c			\
			\
			$(INJECT_BUFFER)injectbuf_create.c		\
			$(INJECT_BUFFER)injectbuf_destroy.c		\
			$(INJECT_BUFFER)injectbuf_empty.c		\
			$(INJECT_BUFFER)injectbuf_ring_inject.c	\
			$(INJECT_BUFFER)injectbuf_write.c		\
			\
			$(CLIENT)client_write_to.c			\
			$(CLIENT)client_close.c				\
			$(CLIENT)client_shutdown.c			\
			\
			$(HANDSHAKER)handshaker_create.c

##########################################################################

INCPATH		+=	$(addprefix $(NETWORK_DIR), $(INC_FOLDER))
SRC		+=	$(addprefix $(NETWORK_DIR), $(NETWORK))
