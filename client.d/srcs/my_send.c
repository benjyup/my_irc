/*
** my_send.c for my_send in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 13:38:49 2017 Benjamin
** Last update Sun Jun 11 21:17:14 2017 Benjamin
*/

#include		<string.h>
#include		<stdio.h>
#include		"client.h"

static t_commands	g_cmd[NB_CLIENT_CMDS] =
    {
      {"/server", &server},
      {"/nick", &nickname},
      {"/list", &channel},
      {"/join", &channel},
      {"/part", &channel},
      {"/users", &users},
      {"/msg", &message},
      {"/help", &usage}
    };

int			tablen(char **tab)
{
  int			i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

static int		is_cmd(const char *cmd)
{
  unsigned int		i;

  i = 0;
  while (i <= NB_CLIENT_CMDS)
    {
      if (!strncmp(g_cmd[i].name, cmd, strlen(g_cmd[i].name)))
	return (i);
      ++i;
    }
  return (R_FAILURE);
}

int			respond(t_client *client,
				const char *buffer)
{
  char			**tab;
  int			ret;
  
  tab = my_str_to_wordtab(buffer, " :");
  if ((ret = is_cmd(buffer)) != R_FAILURE)
    {
      if (g_cmd[ret].ptr_func(client, tab, buffer) == R_FAILURE)
	printf("%s %s\n", g_cmd[ret].name, FAILURE_CMD_MSG);
      else
	printf("%s %s\n", g_cmd[ret].name, SUCCESS_CMD_MSG);
    }
  else if (client->sock_info.sock != R_FAILURE
	   && FD_ISSET(client->sock_info.sock, &client->wfds))
    my_send(client->sock_info.sock, buffer, strlen(buffer));
  free_tab(tab);
  return (R_SUCCESS);
}
