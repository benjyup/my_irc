/*
** function_user.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Tue Jun  6 21:45:11 2017 Jean-Adrien Domage
** Last update Thu Jun  8 00:58:19 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include <string.h>
#include "querry_module.h"
#include "myirc.h"

static int	register_user(t_peer *peer, char *pseudo, char *name)
{
  peer->pseudo = strdup(pseudo);
  peer->name = strdup(name);
}

int	function_user(t_server *serv, t_peer *peer, t_querry *qry)
{

  if (qry->size < 5)
    return (dprintf(peer->fd, "461 USER: Need more params.\r\n"), 1);
  if (peer->name != NULL)
    {
      printf("pass\n");
      return (dprintf(peer->fd, "462 :You are already registered.\r\n"), 1);
    }
  register_user(peer, qry->av[1], qry->av[4]);
  dprintf(peer->fd, "001 %s: registered.\r\n", peer->pseudo);
  return (0);
}
