/*
** write_listener.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Sat Jun  3 22:17:23 2017 Jean-Adrien Domage
** Last update Mon Jun  5 01:48:00 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <unistd.h>
#include "myirc.h"

int	write_listener(t_server *serv, t_peer *peer)
{
  /* int	len; */
  /* int	ret; */

  /* if (peer->rc == peer->wc) */
  /*   return (0); */
  /* else if (peer->wc > peer->rc) */
  /*   len = peer->wc - peer->rc; */
  /* else */
  /*   len = BUFF_MAX - peer->rc; */
  /* ret = write(peer->fd, peer->circular_buff + peer->rc, len); */
  /* dprintf(peer->fd, "\n\r"); */
  /* peer->rc += ret; */
  /* if (peer->rc == BUFF_MAX) */
  /*   peer->rc = 0; */
  return (0);
}
