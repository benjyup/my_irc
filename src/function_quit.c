/*
** function_quit.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Thu Jun  8 00:59:02 2017 Jean-Adrien Domage
** Last update Sun Jun 11 22:18:15 2017 Jean-Adrien Domage
*/

#include <stdio.h>
#include "querry_module.h"
#include "myirc.h"

int	function_quit(t_server *serv, t_peer *peer, t_querry *qry)
{
  if (qry->av[1])
    dprintf(peer->fd, "%s\r\n", qry->av[1]);
  else if (peer->pseudo)
    dprintf(peer->fd, "%s\r\n", peer->pseudo);
  else
    dprintf(peer->fd, "Anonymous\r\n");

  logout(serv, peer);
  return (0);
}
