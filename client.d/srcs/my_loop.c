/*
** my_loop.c for my_loop in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 13:37:27 2017 Benjamin
** Last update Fri Jun  9 12:09:39 2017 Benjamin
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"client.h"

static int	read_server(const int sock, char *buffer)
{
  if ((my_recv(sock, buffer, BUFFER_SIZE)) == 0 ||
    !strcmp(DISCO_MSG, buffer))
      {
	puts(KICKED_MSG);
	return (R_SUCCESS);
      }
  return (R_FAILURE);
}

static int	read_input(char *buffer)
{
  char		*pos_eol;

  if (fgets(buffer, BUFFER_SIZE, stdin))
    {
      if ((pos_eol = strchr(buffer, EOL)))
	buffer[pos_eol - buffer] = 0;
      return (R_SUCCESS);
    }
  return (R_FAILURE);
}

static int	do_select(t_client *client)
{
  int		max_fd;

  FD_ZERO(&client->rfds);
  FD_ZERO(&client->wfds);
  FD_SET(STDIN_FILENO, &client->rfds);
  FD_SET(client->sock_info.sock, &client->rfds);
  FD_SET(client->sock_info.sock, &client->wfds);
  if (client->sock_info.sock == -1)
    max_fd = STDERR_FILENO;
  else
    max_fd = client->sock_info.sock;
  if (select(max_fd + 1,
	     &client->rfds, &client->wfds, NULL, NULL) == R_FAILURE)
    {
      perror(ERR_SELECT);
      return (R_FAILURE);
    }
  return (R_SUCCESS);
}

int		loop(t_client *client)
{
  char		buffer[BUFFER_SIZE];

  while (IS_TRUE)
    {
      if (do_select(client) == R_FAILURE)
	return (R_FAILURE);
      if (FD_ISSET(STDIN_FILENO, &client->rfds))
	{
	  read_input(buffer);
	  if (buffer[0] == '/')
	    buffer[0] = ' ';
	  respond(client, buffer);
	}
      else if (FD_ISSET(client->sock_info.sock, &client->rfds))
	{
	  if (read_server(client->sock_info.sock, buffer) == R_SUCCESS)
	    return (R_SUCCESS);
	  puts(buffer);
	}
    }
  return (R_SUCCESS);
}
