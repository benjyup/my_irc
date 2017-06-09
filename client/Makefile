NAME	= client

CC	= gcc

RM	= rm -f

SRCS	= ./srcs/init_my_client.c \
	  ./srcs/main.c \
	  ./srcs/my_communication.c \
	  ./srcs/my_str_to_wordtab.c \
	  ./srcs/my_usage.c \
	  ./srcs/my_loop.c \
	  ./srcs/my_send.c \
	  ./srcs/my_channel_cmd.c \
	  ./srcs/my_msg_cmd.c \
	  ./srcs/my_nick_cmd.c \
	  ./srcs/my_serv_cmd.c \
	  ./srcs/my_user_cmd.c \
	  ./srcs/useful.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
