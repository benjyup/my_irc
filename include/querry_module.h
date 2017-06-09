/*
** querry_module.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 05:32:38 2017 Jean-Adrien Domage
** Last update Mon Jun  5 06:55:26 2017 Jean-Adrien Domage
*/

#ifndef QUERRY_MODULE_H_
# define QUERRY_MODULE_H_

#include "myirc.h"

typedef struct	s_querry
{
  int		size;
  char		**av;
  char		buff[512];
}		t_querry;

int	server_lexer(t_querry *this);
void	free_lexer(t_querry *this);

#endif /* !QUERRY_MODULE_H_ */
