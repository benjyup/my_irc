/*
** function_mode.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Thu Jun  8 02:29:51 2017 Jean-Adrien Domage
** Last update Thu Jun  8 02:51:12 2017 Jean-Adrien Domage
*/

#include <string.h>
#include <stdio.h>
#include "querry_module.h"
#include "myirc.h"

static int	find_nick(t_server *serv, t_peer *peer, char *s)
{
  int		idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == CLOSE)
        {
          if (serv->peers[idx].pseudo)
            if (strcmp(serv->peers[idx].pseudo, s) == 0)
              {
                dprintf(peer->fd, "311 %s no no %s\r\n", peer->pseudo, peer->name);
                return (0);
              }
        }
      idx += 1;
    }
  return (1);
}

int	function_whois(t_server *serv, t_peer *peer, t_querry *qry)
{
  if (qry->size < 2)
    dprintf(peer->fd, "431 :No nickname given.\r\n");
  if (find_nick(serv, peer, qry->av[1]) == 1)
    {
      dprintf(peer->fd, "401 %s :No such nickname.\r\n", qry->av[1]);
      return (1);
    }
  return (0);
}
