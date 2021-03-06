/*
** selector.h for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 02:25:16 2017 Jean-Adrien Domage
** Last update Sun Jun 11 17:46:06 2017 Jean-Adrien Domage
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
  "privmsg",
  "list",
  NULL
};

# define ARG_NBR	7

int	function_nick(t_server *serv, t_peer *peer, t_querry *qry);
int	function_user(t_server *serv, t_peer *peer, t_querry *qry);
int	function_join(t_server *serv, t_peer *peer, t_querry *qry);
int	function_quit(t_server *serv, t_peer *peer, t_querry *qry);
int	function_part(t_server *serv, t_peer *peer, t_querry *qry);
int	function_privmsg(t_server *serv, t_peer *peer, t_querry *qry);
int	list_channels(t_server *serv, t_peer *peer, t_querry *qry);

int	(*function_ptr[])(t_server *, t_peer *, t_querry *) = {
  function_nick,
  function_user,
  function_join,
  function_quit,
  function_part,
  function_privmsg,
  list_channels
};

#endif /* !SELECTOR_H_ */
