##
## Makefile for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc
## 
## Made by Jean-Adrien Domage
## Login   <jeanadrien.domage@epitech.eu>
## 
## Started on  Fri May 26 11:30:59 2017 Jean-Adrien Domage
## Last update Sun Jun 11 21:39:56 2017 Benjamin
##

SERVER	=	server

CLIENT	=	client

RM	=	rm -f

CC	=	gcc -Iinclude/ -Iclient.d/include/

CFLAG	=	-w -Wextra -Wall -Werror

SRC	=	main.c\
		src/socket.c\
		src/server.c\
		src/select.c\
		src/fd_set_manager.c\
		src/connection_manager.c\
		src/read_listener.c\
		src/write_listener.c\
		src/querry_module.c\
		src/function_join.c\
		src/function_user.c\
		src/function_quit.c\
		src/function_nick.c\
		src/function_part.c\
		src/function_privmsg.c

OBJ	=	$(SRC:.c=.o)

SRC_C	=	./client.d/srcs/init_my_client.c \
		./client.d/srcs/main.c \
		./client.d/srcs/my_communication.c \
		./client.d/srcs/my_str_to_word_tab.c \
		./client.d/srcs/my_usage.c \
		./client.d/srcs/my_loop.c \
		./client.d/srcs/my_send.c \
		./client.d/srcs/my_channel_cmd.c \
		./client.d/srcs/my_msg_cmd.c \
		./client.d/srcs/my_nick_cmd.c \
		./client.d/srcs/my_serv_cmd.c \
		./client.d/srcs/my_user_cmd.c
OBJ_C	=	$(SRC_C:.c=.o)

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(SERVER)

$(CLIENT):	$(OBJ_C)
	$(CC) $(CFLAG) $(OBJ_C) -o $(CLIENT)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_C)

fclean:	clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re:	fclean all

.PHONY:		all clean fclean re
