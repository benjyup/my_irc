/*
** read_listener.c for  in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 20:41:35 2017 Jean-Adrien Domage
** Last update Sat Jun  3 19:12:25 2017 Jean-Adrien Domage
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "myirc.h"

int	circular_write(t_peer *peer, char *s)
{
  int	idx;

  idx = 0;
  while (s[idx])
    {
      if ((peer->wc + 1 == peer->rc - 1) ||
	  (peer->wc == BUFF_MAX && peer->rc == 0))
	  return (strlen(s) - idx);
      peer->circular_buff[peer->wc] = s[idx];
      peer->wc += 1;
      if (peer->wc == BUFF_MAX)
	peer->wc = 0;
      idx += 1;
    }
  printf("Write success\n");
  return (0);
}

int	server_broadcast(t_server *serv, t_peer *peer, char *s)
{
  int	idx;

  idx = 0;
  printf("pass\n");
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == CLOSE && serv->peers[idx].fd != peer->fd)
	{
	  if (circular_write(&serv->peers[idx], s) != 0)
	    printf("Circular_buff :: BIP.\n");
	}
      idx += 1;
    }
}

int	read_listener(t_server *serv, t_peer *peer)
{
  char	buff[512];
  int	ret;

  ret = read(peer->fd, buff, 511);
  if (ret == -1)
    return (perror("read()"), -1);
  else if (ret == 0)
    logout(serv, peer);
  else
    server_broadcast(serv, peer, buff);
  return (0);
}
