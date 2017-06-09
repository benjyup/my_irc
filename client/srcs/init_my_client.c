/*
** init_my_client.c for init_my_client in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 13:19:45 2017 Benjamin
** Last update Mon Jun  5 15:18:01 2017 Benjamin
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<errno.h>
//#include		"my_irc.h"
#include		"client.h"

static int     		init_sock(t_client *client)
{
  if ((client->sock_info.sock = socket(AF_INET,
				       SOCK_STREAM,
				       client->sock_info.pe->p_proto))
      == R_FAILURE)
    {
      perror(ERR_SOCKET);
      return (R_FAILURE);
    }
  client->sock_info.s_in.sin_family = AF_INET;
  return (R_SUCCESS);
}

static int     		init_protocol(t_client *client)
{
  if ((client->sock_info.pe = getprotobyname(PROTOCOL)) == NULL)
    {
      perror(ERR_PROTOCOL);
      return (R_FAILURE);
    }
  return (R_SUCCESS);
}

int			init_client(t_client *client)
{
  if (init_protocol(client) == R_FAILURE)
    return (R_FAILURE);
  if (init_sock(client) == R_FAILURE)
    return (R_FAILURE);
  return (R_SUCCESS);
}
