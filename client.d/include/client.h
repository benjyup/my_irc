/*
** client.h for client in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client/include
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 15:01:42 2017 Benjamin
** Last update Sun Jun 11 22:09:39 2017 Benjamin
*/

#ifndef			CLIENT_H_
# define		CLIENT_H_

# include		<netdb.h>
# include		<arpa/inet.h>
# include		<sys/types.h>
# include		<sys/socket.h>

# define		R_FAILURE	(-1)
# define		R_SUCCESS	(0)
# define		IS_TRUE		(1)

# define		ERR_CLOSE	"error with close()"
# define		ERR_MALLOC	"error with malloc()"
# define		ERR_SOCKET	"error with socket()"
# define		ERR_PROTOCOL	"error with getprotobyname()"
# define		ERR_RECV	"error with read()"
# define		ERR_SEND	"error with write()"
# define		ERR_SELECT	"error with select()"
# define		ERR_CONNECT	"error with connect()"

# define		PROTOCOL	"TCP"
# define		NB_CLIENT_CMDS	(8)

# define		BUFFER_SIZE	(1024)
# define		PROMPT		"[my_irc]$ "
# define		EOL		'\n'

# define		DISCO_MSG	"DISCONNECT"
# define		KICKED_MSG	"Connection with server has been \
closed"
# define		SUCCESS_CMD_MSG	"has been successfully executed."
# define		FAILURE_CMD_MSG	"has failed to execute."

typedef struct		s_sock_info
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			sock;
  int			port;
}			t_sock_info;

typedef struct		s_commands
{
  char			*name;
  int			(*ptr_func)();
}			t_commands;

typedef struct		s_client
{
  int			port;
  t_sock_info		sock_info;
  char			*name;
  fd_set		wfds;
  fd_set		rfds;
}			t_client;

int			my_send(const int socket,
				const char *buffer,
				const size_t len);
int			my_recv(const int socket,
				char *buffer,
				const size_t len);
int			usage();
int			init_client(t_client *client);
void			set_addr(t_client *client, const char *address);
void			set_port(t_client *client, const int port);
int			do_connect(t_client *client);
int			loop(t_client *client);
int			respond(t_client *client, const char *buffer);
char			**my_str_to_wordtab(const char *str, char *sep);
int			server(t_client *client, char **tab);
int			tablen(char **tab);
int			set_connection(t_client *client, char **tab);
int			nickname(t_client *client, char **tab, const char *name);
int			channel(t_client *client, char **tab, const char *name);
int			users(t_client *client, char **tab, const char *name);
int			message(t_client *client, char **tab, const char *name);
void			free_tab(char **tab);

#endif			/* !CLIENT_H_ */
