/*
** my_msg_cmd.c for my_msg_cmd in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client/srcs
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 17:48:41 2017 Benjamin
** Last update Mon Jun  5 17:49:05 2017 Benjamin
*/

#include			<string.h>
#include			"client.h"

int				message(t_client *client, char **tab, const char *name)
{
  if (tablen(tab) < 3)
    return (R_FAILURE);
  my_send(client->sock_info.sock, name, strlen(name));
  return (R_SUCCESS);
}
