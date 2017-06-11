/*
** function_privmsg.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Sat Jun 10 17:58:52 2017 Jean-Adrien Domage
** Last update Sun Jun 11 18:11:19 2017 Jean-Adrien Domage
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "querry_module.h"
#include "myirc.h"

int	print_to_chan(t_server *serv,
		      t_peer *peer,
		      char *target,
		      char *msg)
{
  int	idx;
  int	jdx;

  jdx = 0;
  printf("privmsg test\n");
  if ((idx = find_chan(serv, target)) != -1)
    {
      while (jdx < 10)
	{
	  if (serv->chan[idx].peers[jdx] != NULL && serv->chan[idx].peers[jdx]->fd != peer->fd)
	    {
	      dprintf(serv->chan[idx].peers[jdx]->fd, ":%s PRIVMSG %s %s\r\n", peer->pseudo, target, msg);
	      return (0);
	    }
	  jdx += 1;
	}
    }
  return (1);
}

int	print_to_peer(t_server *serv,
		      t_peer *peer,
		      char *target,
		      char *msg)
{
  int	idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].pseudo)
	if (strcasecmp(serv->peers[idx].pseudo, target) == 0)
	{
	  dprintf(serv->peers[idx].fd, ":%s PRIVMSG %s %s\r\n", peer->pseudo, target, msg);
	  return (0);
	}
      idx += 1;
    }
  return (1);
}

int     function_privmsg(t_server *serv,
			 t_peer *peer,
			 t_querry *qry)
{
  if (qry-> size < 3)
    return (dprintf(peer->fd, "412 PRIVMSG: no text to send\r\n"), 1);
  if (qry->av[1][0] == '#' ||
      qry->av[1][0] == '&')
    {
      if (print_to_chan(serv, peer, qry->av[1], qry->av[2]) == 1)
        {
	  dprintf(peer->fd, "404 PRIVMSG: Cannot send to channel.\r\n");
	  return (1);
	}
      return (0);
    }
  else
    if (print_to_peer(serv, peer, qry->av[1], qry->av[2]) == 1)
      {
	dprintf(peer->fd, "401 PRIVMSG: No such nick\r\n");
	return (1);
      }
  return (0);
}
