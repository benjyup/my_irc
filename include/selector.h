/*
** selector.h for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/include
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Mon Jun  5 02:25:16 2017 Jean-Adrien Domage
** Last update Thu Jun  8 02:56:36 2017 Jean-Adrien Domage
*/

#ifndef SELECTOR_H_
# define SELECTOR_H_

#include "myirc.h"
#include "querry_module.h"

char	*function_name[] = {
  "user",
  "join",
  "quit",
  "nick",
  "mode",
  "whois",
  NULL
};

# define ARG_NBR	6

int	function_user(t_server *serv, t_peer *peer, t_querry *qry);
int	function_join(t_server *serv, t_peer *peer, t_querry *qry);
int	function_quit(t_server *serv, t_peer *peer, t_querry *qry);
int	function_nick(t_server *serv, t_peer *peer, t_querry *qry);
int	function_mode(t_server *serv, t_peer *peer, t_querry *qry);
int	function_whois(t_server *serv, t_peer *peer, t_querry *qry);

int	(*function_ptr[])(t_server *, t_peer *, t_querry *) = {
  function_user,
  function_join,
  function_quit,
  function_nick,
  function_mode,
  function_whois
};

#endif /* !SELECTOR_H_ */
