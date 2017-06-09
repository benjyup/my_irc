/*
** my_serv_cmd.c for my_serv_cmd in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client/srcs
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 17:50:16 2017 Benjamin
** Last update Mon Jun  5 17:50:48 2017 Benjamin
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"client.h"

static int		my_isdigit(char *str, char *comp)
{
  int			i;
  unsigned int		j;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (comp[j] != '\0' && comp[j] != str[i])
	++j;
      if (j > strlen(comp))
	return (R_FAILURE);
      ++i;
    }
  return (R_SUCCESS);
}

int			server(t_client *client, char **tab)
{
  if (tablen(tab) != 3)
    return (R_FAILURE);
  if (my_isdigit(tab[1], "0123456789.") == R_FAILURE)
    return (R_FAILURE);
  if (my_isdigit(tab[2], "0123456789") == R_FAILURE)
    return (R_FAILURE);
  if (set_connection(client, tab) == EXIT_FAILURE)
    return (R_FAILURE);
  return (R_SUCCESS);
}
