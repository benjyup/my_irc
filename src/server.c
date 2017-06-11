/*
** server.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 16:24:03 2017 Jean-Adrien Domage
** Last update Sun Jun 11 18:28:42 2017 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "myirc.h"

static t_server	*g_serv = NULL;

void	sig_handler(int sig)
{
  int	i;

  i = 0;
  printf("SIGINT received\n");
  if (g_serv == NULL)
    exit(0);
  while (i < MAX_PEER)
    {
      if (g_serv->peers[i].slot == CLOSE)
	{
	  dprintf(g_serv->peers[i].fd, "Connection close by server.\r\n");
	  close(g_serv->peers[i].fd);
	}
      i += 1;
    }
  exit(0);
}

static void	init_peers(t_server *serv)
{
  int		idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      serv->peers[idx].slot = OPEN;
      serv->peers[idx].wc = 0;
      serv->peers[idx].rc = 0;
      serv->peers[idx].pseudo = NULL;
      serv->peers[idx].name = NULL;
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
      serv->chan[idx].name = NULL;
      idx += 1;
    }
}

void	init_server(t_server *serv)
{
  init_peers(serv);
  init_chan(serv);
  g_serv = serv;
  signal(SIGINT, sig_handler);
}
