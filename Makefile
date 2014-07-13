##
## Makefile for Makefile in /home/mougen_v/rendus/PSU_2013_zappy
##
## Made by Valentin
## Login   <mougen_v@epitech.net>
##
## Started on  Sun Jul 13 18:08:39 2014 Valentin
## Last update Sun Jul 13 18:08:41 2014 Valentin
##

AI		=	AI/
SERVER		=	server/

LDPATH		=	libs/

all		:
			@(make -j8 -C $(LDPATH))
			@(make -j8 -C $(AI))
			@(make -j8 -C $(SERVER))

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
