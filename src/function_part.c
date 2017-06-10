/*
** funcion_part.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Sat Jun 10 16:56:36 2017 Jean-Adrien Domage
** Last update Sat Jun 10 17:13:03 2017 Jean-Adrien Domage
*/

#include <stdlib.h>
#include <stdio.h>
#include "querry_module.h"
#include "myirc.h"

static int      remove_to_chan(t_server    *serv,
                            t_peer      *peer,
                            char        *s)
{
  int		idx;
  int		jdx;

  jdx =	0;
  if ((idx = find_chan(serv, s)) == -1)
    {
      dprintf(peer->fd, "403 %s: no such channel.\r\n", s);
      return (1);
    }
  while	(jdx < 10)
    {
      if (serv->chan[idx].peers[jdx]->fd == peer->fd)
        {
	  dprintf(peer->fd, ":%s PART %s\r\n", peer->pseudo, s);
	  serv->chan[idx].peers[jdx] = NULL;
          return (0);
        }
      jdx += 1;
    }
  dprintf(peer->fd, "442 %s: your\'re not on that channel.\r\n", s);
  return (1);
}


int     function_part(t_server *serv,
                      t_peer *peer,
                      t_querry *qry)
{
  if (!qry->av[1])
    return (dprintf(peer->fd, "461 JOIN: to few paramater\r\n"), 1);
  if (qry->av[1][0] == '#' ||
      qry->av[1][0] == '&')
    {
      if (remove_to_chan(serv, peer, qry->av[1]) == 1)
        return (1);
      return (0);
    }
  else
    return (dprintf(peer->fd, "475 %s: The given channel mask was invalid\r\n", qry->a\
v[1]), 1);
  return (0);
}

