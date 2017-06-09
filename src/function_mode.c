/*
** function_mode.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Thu Jun  8 02:29:51 2017 Jean-Adrien Domage
** Last update Thu Jun  8 02:34:58 2017 Jean-Adrien Domage
*/

#include "stdio.h"
#include "querry_module.h"
#include "myirc.h"

int	function_mode(t_server *serv, t_peer *peer, t_querry *qry)
{
  dprintf(peer->fd, "221 i\r\n");
  return (0);
}
