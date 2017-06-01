/*
** myirc.h for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May 26 11:36:51 2017 Jean-Adrien Domage
** Last update Wed May 31 22:27:22 2017 Jean-Adrien Domage
*/

#ifndef MYIRC_H_
# define MYIRC_H_

#include <netinet/in.h>

# define USAGE	"USAGE: %s port\n"

# define MAX_PEER	100
# define MAX_CHAN	10

typedef enum	s_peer_state
  {
    OPEN = 1,
    CLOSE = 0
  }		t_peer_state;

typedef struct		s_peer
{
  t_peer_state		slot;
  int			fd;
  struct sockaddr_in	addr;
  char			name[200];
  char			circular_buff[512];
  int			rc;
  int			wc;
}			t_peer;

typedef enum	s_chan_state
  {
    READY = 1,
    DOWN = 0
  }		t_chan_state;

typedef struct	s_channel
{
  char		name[200];
  t_chan_state	state;
  t_peer	*peers[10];
  int		peers_nb;
}		t_channel;

typedef struct		s_server
{
  int			fd;
  int			port;
  struct sockaddr_in	addr;
  fd_set		readfs;
  fd_set		writefs;
  t_peer		peers[MAX_PEER];
  t_channel		chan[MAX_CHAN];
}			t_server;

int	bind_socket(int fd, int port, t_server *serv);
int    	init_socket_server(void);
void   	init_server(t_server *serv);
int	relay_channel(t_server *serv);
int	reset_fd_set(t_server *serv);
int	connection_manager(t_server *serv);
int	read_listener(t_server *serv, t_peer *peer);
int	logout(t_server *serv, t_peer *peer);

#endif /* !MYIRC_H_ */
