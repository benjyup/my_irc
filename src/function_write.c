/*
** function_write.c for myric in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 02:40:21 2017 Jean-Adrien Domage
** Last update Sun Jun 11 18:34:15 2017 Jean-Adrien Domage
*/

#include "myirc.h"

int     circular_write(t_peer *peer, char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '\n')
        s[i] = '\r';
      i += 1;
    }
  dprintf(peer->fd, "%s\n", s);
  return (0);
}

int     server_broadcast(t_server *serv, t_peer *peer, char *s)
{
  int   idx;

  idx = 0;
  printf("pass\n");
  if (s[0] == '\n')
    return (0);
  while (idx < MAX_PEER)
    {
      if (serv->peers[idx].slot == CLOSE && serv->peers[idx].fd != peer->fd)
        {
          if (circular_write(&serv->peers[idx], s) != 0)
            printf("Circular_buff :: BIP.\n");
        }
      idx += 1;
    }
}
