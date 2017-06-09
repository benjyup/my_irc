/*
** tablen.c for tablen in /home/naina_r//my_irc
** 
** Made by richard naina
** Login   <naina_r@epitech.net>
** 
** Started on  Wed Apr 24 15:20:23 2013 richard naina
** Last update Wed Apr 24 15:22:55 2013 richard naina
*/

#include		<stdlib.h>

int			tablen(char **tab)
{
  int			i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}
