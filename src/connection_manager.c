/*
** commande_server.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 15:52:38 2017 Jean-Adrien Domage
** Last update Thu Jun  8 00:54:56 2017 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "myirc.h"

static t_peer	*get_open_slot(t_server *serv)
{
  int		idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == OPEN)
	return ((t_peer *)&serv->peers[idx]);
      idx += 1;
    }
  return (NULL);
}

int	logout(t_server *serv, t_peer *peer)
{
  if (close(peer->fd) == -1)
    return (perror("close()"), -1);
  peer->slot = OPEN;
  if (peer->pseudo)
    free(peer->pseudo);
  if (peer->name)
    free(peer->name);
  peer->pseudo = NULL;
  peer->name = NULL;
  return (0);
}

int			connection_manager(t_server *serv)
{
  int                   client_fd;
  struct sockaddr_in    client_addr;
  socklen_t             client_size;
  t_peer		*slot;
  
  client_size = sizeof(client_addr);
  if ((client_fd = accept(serv->fd,
			  (struct sockaddr *)&client_addr,
			  &client_size)) == -1)
    return (perror("accept()"), -1);
  if (!(slot = get_open_slot(serv)))
    {
      if (close(client_fd) == -1)
	perror("close()");
      printf("Connection Manager: no OPEN slot for new peer.\n");
      return (-1);
    }
  slot->fd = client_fd;
  slot->addr = client_addr;
  slot->slot = CLOSE;
  dprintf(slot->fd, "Wellcome to the internet relay network\r\n");
  return (0);
}
