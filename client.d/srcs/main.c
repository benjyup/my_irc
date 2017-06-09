/*
** main.c for main in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 12:59:18 2017 Benjamin
** Last update Fri Jun  9 12:11:44 2017 Benjamin
*/

#include		<stdio.h>
#include		<errno.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<netinet/in.h>
#include		"client.h"

int			set_connection(t_client *client, char **av)
{
  set_addr(client, av[1]);
  set_port(client, atoi(av[2]));
  if (init_client(client) == R_FAILURE)
    return (R_FAILURE);
  if (do_connect(client) == R_FAILURE)
    return (R_FAILURE);
  return (R_SUCCESS);
}

void			set_addr(t_client *client, const char *address)
{
  client->sock_info.s_in.sin_addr.s_addr = inet_addr(address);
}

void			set_port(t_client *client, const int port)
{
  client->sock_info.s_in.sin_port = htons(port);
}

int			do_connect(t_client *client)
{
  if (connect(client->sock_info.sock,
	      (const struct sockaddr *)&client->sock_info.s_in,
	      sizeof(client->sock_info.s_in)))
    {
      perror(ERR_CONNECT);
      close(client->sock_info.sock);
      return (R_FAILURE);
    }
  return (R_SUCCESS);
}

int			main(int ac, char **av)
{
  t_client		client;

  client.name = NULL;
  client.sock_info.sock = -1;
  usage();
  if (ac != 3)
    return (EXIT_FAILURE);
  if (set_connection(&client, av) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  loop(&client);
  if (client.sock_info.sock != -1)
     close(client.sock_info.sock);
  return (EXIT_SUCCESS);
}
