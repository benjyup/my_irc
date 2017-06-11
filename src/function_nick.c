/*
** function_user.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Tue Jun  6 21:45:11 2017 Jean-Adrien Domage
** Last update Sun Jun 11 18:32:34 2017 Jean-Adrien Domage
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "querry_module.h"
#include "myirc.h"

static int	register_user(t_server *serv, t_peer *peer, char *pseudo)
{
  int		idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == CLOSE)
        {
	  if (serv->peers[idx].pseudo)
	    if (strcmp(serv->peers[idx].pseudo, pseudo) == 0)
	      {
		pseudo = strdup(pseudo);
		pseudo = realloc(pseudo, strlen(pseudo) + 1);
		pseudo = strcat(pseudo, "_");
	      }
	}
      idx += 1;
    }
  if (peer->old)
    free(peer->old);
  peer->old = peer->pseudo;
  peer->pseudo = strdup(pseudo);
  return (0);
}

int	function_nick(t_server *serv, t_peer *peer, t_querry *qry)
{
  if (qry->size < 2)
    return (dprintf(peer->fd, "461 USER: Need more params.\r\n"), 1);
  if (strcmp(qry->av[1], "anonymous") == 0)
    {
      dprintf(peer->fd, "432 %s: already exist.\r\n", qry->av[1]);
      return (1);
    }
  if (qry->av[1])
    if (register_user(serv, peer, qry->av[1]) == 1)
      return (1);
  if (peer->old)
      dprintf(peer->fd, ":%s NICK %s\r\n", peer->old, peer->pseudo);
  else
    {
      dprintf(peer->fd, ": NICK %s\r\n", peer->pseudo);
      dprintf(peer->fd, "001\r\n");
    }
  return (0);
}
