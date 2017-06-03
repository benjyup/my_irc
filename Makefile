##
## Makefile for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc
## 
## Made by Jean-Adrien Domage
## Login   <jeanadrien.domage@epitech.eu>
## 
## Started on  Fri May 26 11:30:59 2017 Jean-Adrien Domage
## Last update Wed May 31 21:16:12 2017 Jean-Adrien Domage
##

SERVER	=	server

RM	=	rm -f

CC	=	gcc -g3 -Iinclude/

CFLAG	=	-w -Wextra -Wall -Werror

CLIENT	=	client

SRC	=	main.c\
		src/socket.c\
		src/server.c\
		src/select.c\
		src/fd_set_manager.c\
		src/connection_manager.c\
		src/read_listener.c\

OBJ	=	$(SRC:.c=.o)

all:		$(SERVER)

$(SERVER):	$(OBJ)
	$(CC) $(OBJ) -o $(SERVER)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(SERVER)

re:	fclean all

.PHONY:		all clean fclean re
