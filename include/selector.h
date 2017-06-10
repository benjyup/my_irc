/*
** selector.h for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 02:25:16 2017 Jean-Adrien Domage
** Last update Sat Jun 10 16:57:37 2017 Jean-Adrien Domage
*/

#ifndef SELECTOR_H_
# define SELECTOR_H_

#include "myirc.h"
#include "querry_module.h"

char	*function_name[] = {
  "nick",
  "user",
  "join",
  "quit",
  "part",
  NULL
};

# define ARG_NBR	5

int	function_nick(t_server *serv, t_peer *peer, t_querry *qry);
int	function_user(t_server *serv, t_peer *peer, t_querry *qry);
int	function_join(t_server *serv, t_peer *peer, t_querry *qry);
int	function_quit(t_server *serv, t_peer *peer, t_querry *qry);
int	function_part(t_server *serv, t_peer *peer, t_querry *qry);

int	(*function_ptr[])(t_server *, t_peer *, t_querry *) = {
  function_nick,
  function_user,
  function_join,
  function_quit,
  function_part
};

#endif /* !SELECTOR_H_ */
