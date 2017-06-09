/*
** my_nick_msg.c for my_nick_cmd in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client/srcs
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 17:49:26 2017 Benjamin
** Last update Fri Jun  9 12:04:55 2017 Benjamin
*/

#include		<string.h>
#include		"client.h"

int			nickname(t_client *client, char **tab, const char *name)
{
  if (tablen(tab) != 2)
    return (R_FAILURE);
  client->name = tab[1];
  my_send(client->sock_info.sock, name, strlen(name));
  return (R_SUCCESS);
}
