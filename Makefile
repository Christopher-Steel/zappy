AI		=	AI/
SERVER		=	server/

LDPATH		=	libs/

all		:
			@(make -C $(LDPATH))
			@(make -C $(AI))
			@(make -C $(SERVER))

clean		:
			@(cd $(LDPATH) && make clean)
			@(cd $(AI) && make clean)
			@(cd $(SERVER) && make clean)

fclean		:
			@(cd $(LDPATH) && make fclean)
			@(cd $(AI) && make fclean)
			@(cd $(SERVER) && make fclean)

re		:
			@(cd $(LDPATH) && make re)
			@(cd $(AI) && make re)
			@(cd $(SERVER) && make re)

.PHONY		:	all clean fclean re
