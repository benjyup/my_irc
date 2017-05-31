/*
** myirc.h for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May 26 11:36:51 2017 Jean-Adrien Domage
** Last update Wed May 31 17:11:07 2017 Jean-Adrien Domage
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
  t_peer		peers[MAX_PEER];
  t_channel		chan[MAX_CHAN];
}			t_server;

int	bind_socket(int fd, int port, t_server *serv);
int    	init_socket_server(void);
void   	init_server(t_server *serv);

#endif /* !MYIRC_H_ */
