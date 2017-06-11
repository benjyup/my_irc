/*
** my_user_cmd.c for my_user_cmd in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client/srcs
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 17:51:20 2017 Benjamin
** Last update Sun Jun 11 18:55:18 2017 Benjamin
*/

#include		<string.h>
#include		"client.h"

int			users(t_client *client, char **tab, const char *name)
{
  if (tablen(tab) != 1)
    return (R_FAILURE);
  my_send(client->sock_info.sock, name, strlen(name));
  return (R_SUCCESS);
}
