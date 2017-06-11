/*
** select.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 17:32:24 2017 Jean-Adrien Domage
** Last update Sun Jun 11 18:35:41 2017 Jean-Adrien Domage
*/

#include <stdlib.h>
#include <stdio.h>
#include "myirc.h"

static void   handle_peer(t_server *serv)
{
  int           idx;

  idx = 0;
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == CLOSE)
	{
	  if (FD_ISSET(serv->peers[idx].fd, &serv->writefs))
	    {
	      write_listener(serv, (t_peer *)&serv->peers[idx]);
	    }
	  if (FD_ISSET(serv->peers[idx].fd, &serv->readfs))
	    {
	      read_listener(serv, (t_peer *)&serv->peers[idx]);
	    }
	}
      idx += 1;
    }
}

int	relay_channel(t_server *serv)
{
  int	higherfd;
  int	err;

  err = 0;
  while (err != -1)
    {
      higherfd = reset_fd_set(serv);
      err = select(higherfd + 1, &serv->readfs, &serv->writefs, NULL, NULL);
      if (err == -1)
	return (perror("select()"), -1);
      if (FD_ISSET(serv->fd, &serv->readfs))
	{
	  if (connection_manager(serv) == -1)
	    printf("Unable to manage new connection.\n");
	  else
	    printf("New incomming connection.\n");
	}
      handle_peer(serv);
    }
  return (0);
}
