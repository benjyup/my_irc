/*
** my_usage.c for my_usage in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 12:58:59 2017 Benjamin
** Last update Sun Jun 11 18:38:24 2017 Jean-Adrien Domage
*/

#include	<stdio.h>
#include	"client.h"

int		usage()
{
  puts("\nUsage of my_irc:");
  puts("/help : to show usage.");
  puts("/server _host_[ :_port_] to connect to server.");
  puts("/nick _nickname_ : defines the bickname of the user in the channel.");
  puts("/list [string] : list the channels available on the server.\
Displays only the channels containing the string 'string' if\
 it is specified.");
  puts("/join _channel_ : joins a channel on server.");
  puts("/part _channel_ : leave the channel.");
  puts("/users : display the users connected to the channel \
(display the nicknames of course).");
  puts("/msg nickname _message_ : sends a message to a specific user.");
  puts("_message_ : sends a message to all users connected to the channel.");
  puts("\n");
  return (R_SUCCESS);
}
