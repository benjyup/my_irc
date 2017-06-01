/*
** read_listener.c for  in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 20:41:35 2017 Jean-Adrien Domage
** Last update Thu Jun  1 12:09:19 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <unistd.h>
#include "myirc.h"

int	circular_write(char *s)
{
  return (0);
}

int	read_listener(t_server *serv, t_peer *peer)
{
  char	buff[512];
  int	ret;
  int	read;

  ret = read(peer->fd, buff, 511);
  if (ret == -1)
    return (perror("read()"), -1);
  else if (ret == 0)
    logout(serv, peer);
  else
    printf("read: %s\n", buff);
  return (0);
}
