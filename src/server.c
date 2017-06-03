/*
** server.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 16:24:03 2017 Jean-Adrien Domage
** Last update Sat Jun  3 19:08:44 2017 Jean-Adrien Domage
*/

#include <stdlib.h>
#include <string.h>
#include "myirc.h"

static void	init_peers(t_server *serv)
{
  int		idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      serv->peers[idx].slot = OPEN;
      serv->peers[idx].wc = 0;
      serv->peers[idx].rc = 0;
      strcpy(serv->peers[idx].name,
	     "Anonymous");
      idx += 1;
    }
}

static void	init_chan(t_server *serv)
{
  int		idx;
  int		peer_idx;

  idx = 0;
  while (idx < MAX_CHAN)
    {
      peer_idx = 0;
      serv->chan[idx].state = DOWN;
      serv->chan[idx].peers_nb = 0;
      while (peer_idx < 10)
	{
	  serv->chan[idx].peers[peer_idx] = NULL;
	  peer_idx += 1;
	}
      serv->chan[idx].name[0] = idx + '0';
      serv->chan[idx].name[1] = '\0';
      idx += 1;
    }
}

void	init_server(t_server *serv)
{
  init_peers(serv);
  init_chan(serv);
}
