/*
** socket.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
  if (bind(fd,
           (const struct sockaddr *)&addr,
           sizeof(*addr)) == -1)** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Fri May 26 11:39:01 2017 Jean-Adrien Domage
** Last update Wed May 31 17:12:07 2017 Jean-Adrien Domage
*/

#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include "myirc.h"

int		bind_socket(int fd, int port, t_server *serv)
{
  serv->addr.sin_family = AF_INET;
  serv->addr.sin_port = htons(port);
  serv->addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd,
           (const struct sockaddr *)&serv->addr,
           sizeof(serv->addr)) == -1)
    return (perror("bind()"), -1);
  if (listen(fd, 100) == -1)
    return (perror("listen()"), -1);
  return (0);
}

int			init_socket_server(void)
{
  struct protoent	*pe;
  int			fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (perror("getprotobyname()"), -1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    return (perror("socket()"), -1);
  return (fd);
}
