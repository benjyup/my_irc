/*
** function_join.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 02:29:14 2017 Jean-Adrien Domage
** Last update Fri Jun  9 10:08:52 2017 Jean-Adrien Domage
*/

#include <string.h>
#include <stdio.h>
#include "myirc.h"
#include "querry_module.h"

static	int	find_chan(t_server *serv, char *s)
{
  int		idx;

  idx = 0;
  while (idx < MAX_CHAN)
    {
      if (strcmp(serv->chan[idx].name, s) == 0)
	return (idx);
      idx += 1;
    }
  return (-1);
}

static int	add_to_chan(t_server	*serv,
			    t_peer	*peer,
			    char	*s)
{
  /* if (find_chan() = -1) */
  /*   { */
      
  /*   } */
}

int	function_join(t_server *serv,
		      t_peer *peer,
		      t_querry *qry)
{
  if (!qry->av[1])
    return (dprintf(peer->fd, "461 JOIN: to few paramater\r\n"), 1);
  if (qry->av[1][0] == '#' ||
      qry->av[1][0] == '&')
    {
      if (add_to_chan(serv, peer, qry->av[1]) == 1)
	return (1);
      return (0);
    }
  else
    return (dprintf(peer->fd, "475 %s: The given channel mask was invalid\r\n", qry->av[1]), 1);
  return (0);
}
