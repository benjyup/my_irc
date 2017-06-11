/*
** function_join.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 02:29:14 2017 Jean-Adrien Domage
** Last update Sun Jun 11 17:46:39 2017 Jean-Adrien Domage
*/

#include <string.h>
#include <stdio.h>
#include "myirc.h"
#include "querry_module.h"

int	find_chan(t_server *serv, char *s)
{
  int		idx;

  idx = 0;
  while (idx < MAX_CHAN)
    {
      if (serv->chan[idx].name)
	if (strcmp(serv->chan[idx].name, s) == 0)
	  return (idx);
      idx += 1;
    }
  return (-1);
}

int	list_channels(t_server *server,
		      t_peer *peer,
		      const char *name)
{
  int		idx;

  idx = 0;
  while (idx < MAX_CHAN)
    {
      if (server->chan[idx].state == READY)
	dprintf(peer->fd, "%s\r\n", server->chan[idx].name);
      idx++;
    }
  dprintf(peer->fd, "322\r\n");
  return (0);
}

static int	get_new_chan(t_server *serv, char *s)
{
  int		idx;

  idx = 0;
  while (idx < MAX_CHAN)
    {
      if (serv->chan[idx].state == DOWN)
	{
	  serv->chan[idx].name = strdup(s);
	  serv->chan[idx].state = READY;
	  serv->chan[idx].peers_nb = 0;
	  return (idx);
	}
      idx += 1;
    }
  return (-1);
}

static int	add_to_chan(t_server	*serv,
			    t_peer	*peer,
			    char	*s)
{
  int		idx;
  int		jdx;

  jdx = 0;
  if ((idx = find_chan(serv, s)) == -1)
    {
      idx = get_new_chan(serv, s);
    }
  while (jdx < 10)
    {
      if (serv->chan[idx].peers[jdx] == NULL)
	{
	  serv->chan[idx].peers[jdx] = peer;
	  dprintf(peer->fd, ":%s JOIN %s\r\n", peer->pseudo, s);
	  dprintf(peer->fd, "332\r\n");
	  return (0);
	}
      jdx += 1;
    }
  return (1);
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
