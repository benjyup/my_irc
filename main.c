/*
** main.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May 26 11:35:32 2017 Jean-Adrien Domage
** Last update Wed May 31 19:05:18 2017 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myirc.h"

int	argument_controler(int ac, char **av)
{
  int	port;
  char	*err;

  if (ac != 2)
    return (printf(USAGE, av[0]), 1);
  if (strcmp(av[1], "--help") == 0)
    return (printf(USAGE, av[0]), 1);    
  port = strtol(av[1], &err, 10);
  if (err[0] != '\0')
    return (printf("PARSER: Invalide port.\n"), 1);
  return (port);
}

int			main(int ac, char **av)
{
  t_server		serv;
  
  init_server(&serv);
  if ((serv.port = argument_controler(ac, av)) == 1)
    return (84);
  if ((serv.fd = init_socket_server()) == -1)
    return (84);
  if ((bind_socket(serv.fd, serv.port, &serv)) == -1)
    return (84);
  if (relay_channel(&serv) == -1)
    return (84);
  if (close(serv.fd) == -1)
    return (perror("close()"), 84);
  return (0);
}
