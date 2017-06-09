/*
** fd_set_manager.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 17:45:06 2017 Jean-Adrien Domage
** Last update Thu Jun  8 00:53:41 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include "myirc.h"

static int	reset_loop(t_server *serv)
{
  int		idx;
  int		higher;

  idx = 0;
  higher = serv->fd;
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == CLOSE)
	{
	  if (serv->peers[idx].fd > higher)
	    higher = serv->peers[idx].fd;
	  FD_SET(serv->peers[idx].fd, &serv->readfs);
	  FD_SET(serv->peers[idx].fd, &serv->writefs);
	}
      idx += 1;
    }
  return (higher);
}

int	reset_fd_set(t_server *serv)
{
  int	idx;
  int	higher;

  idx = 0;
  FD_ZERO(&serv->readfs);
  FD_ZERO(&serv->writefs);
  FD_SET(serv->fd, &serv->readfs);
  higher = reset_loop(serv);
  return (higher);
}
