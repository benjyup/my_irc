/*
** read_listener.c for  in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 20:41:35 2017 Jean-Adrien Domage
** Last update Wed Jun  7 23:39:00 2017 Jean-Adrien Domage
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "myirc.h"
#include "querry_module.h"
#include "selector.h"

int	server_parser(t_server *serv,
		      t_peer *peer,
		      t_querry *qry)
{
  int	idx;

  idx = 0;
  while (idx < ARG_NBR)
    {
      if (strcasecmp(function_name[idx], qry->av[0]) == 0)
	return ((function_ptr[idx])(serv, peer, qry));
      idx += 1;
    }
  if (idx == ARG_NBR)
    dprintf(peer->fd, "421 %s: commande unknow.\r\n", qry->av[0]);
  return (0);
}

int		read_listener(t_server *serv, t_peer *peer)
{
  t_querry	qry;
  char		buff[512];
  int		ret;

  qry.av = NULL;
  memset(qry.buff, 0, 512);
  ret = read(peer->fd, qry.buff, 512);
  if (ret == -1)
    return (perror("read()"), -1);
  else if (ret == 0)
    logout(serv, peer);
  else
    {
      if (server_lexer(&qry) == 1)
	return (-1);
      server_parser(serv, peer, &qry);
    }
  free_lexer(&qry);
  return (0);
}
