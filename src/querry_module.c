/*
** querry_module.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 05:32:06 2017 Jean-Adrien Domage
** Last update Fri Jun  9 13:53:44 2017 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myirc.h"
#include "querry_module.h"

static char     **lexer_tab(char **old, int size)
{
  char          **new;
  int           i;

  i = 0;
  if (!(new = malloc(sizeof(char *) * (size + 1))))
    return (perror("malloc"), NULL);
  new[size] = NULL;
  if (old == NULL)
    return (new);
  while (old[i])
    {
      new[i] = old[i];
      i += 1;
    }
  if (old)
    free(old);
  return (new);
}

static void	set_space_bel(t_querry *this)
{
  int		idx;
  int		flag;

  idx = 0;
  flag = 0;
  while (this->buff[idx])
    {
      if (this->buff[idx] == ':')
	flag = 1;
      if (flag == 1 && this->buff[idx] == ' ')
	this->buff[idx] = '\a';
      idx += 1;
    }
}

static void	reset_space_bel(t_querry *this)
{
  int		idx;

  idx = 0;
  while (this->av[this->size - 1][idx] != '\0')
    {
      if (this->av[this->size - 1][idx] == '\a')
	this->av[this->size - 1][idx] = ' ';
      idx += 1;
    }
}

int     server_lexer(t_querry *this)
{
  int   size;
  char  *tmp;

  size = 0;
  if (this->buff[0] == '\n')
    return (1);
  if (!(this->av = lexer_tab(NULL, size)))
    return (1);
  set_space_bel(this);
  tmp = strtok(this->buff, " \n\r");
  while (tmp)
    {
      if (!(this->av = lexer_tab(this->av, ++size)))
        return (1);
      this->av[size - 1] = tmp;
      tmp = strtok(NULL, " \n\r");
    }
  this->size = size;
  reset_space_bel(this);
  return (0);
}

void	free_lexer(t_querry *this)
{
  if (this->av)
    free(this->av);
}
