/*
** function_user.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Tue Jun  6 21:45:11 2017 Jean-Adrien Domage
** Last update Fri Jun  9 14:24:45 2017 Jean-Adrien Domage
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
  dprintf(peer->fd, "001 %s: registered.\r\n", peer->pseudo);
  return (0);
}
