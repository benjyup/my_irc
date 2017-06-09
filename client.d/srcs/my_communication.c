/*
** my_send.c for my_send in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 12:59:31 2017 Benjamin
** Last update Mon Jun  5 13:26:33 2017 Benjamin
*/

#include	<unistd.h>
#include	<errno.h>
#include	<stdio.h>
#include	"client.h"

int		my_send(const int socket,
			const char *buffer,
			const size_t len)
{
  int		ret;

  if ((ret = write(socket, buffer, len)) == R_FAILURE)
    {
      perror(ERR_SEND);
      return (R_FAILURE);
    }
  return (ret);
}

int		my_recv(const int socket,
			char *buffer,
			const size_t len)
{
  int		ret;

  if ((ret = read(socket, buffer, len - 1)) == R_FAILURE)
    {
      perror(ERR_RECV);
      return (R_FAILURE);
    }
  buffer[ret] = '\0';
  return (ret);
}
