/*
** my_usage.c for my_usage in /home/peixot_b/Epitech/Tek2/PSU/PSU_2016_myirc/client
** 
** Made by Benjamin
** Login   <benjamin.peixoto@epitech.eu>
** 
** Started on  Mon Jun  5 12:58:59 2017 Benjamin
** Last update Sun Jun 11 21:39:01 2017 Benjamin
*/

#include	<stdio.h>
#include	"client.h"

int		usage()
{
  printf("Usage of my_irc: ./client [IP ADDRESS] [PORT]\n");
  printf("/help : to show usage.\n");
  printf("/server _host_[ :_port_] to connect to server.\n");
  printf("/nick _nickname_ : defines the bickname of the user in the channel.\n");
  printf("/list [string] : list the channels available on the server.\
Displays only the channels containing the string 'string' if\
 it is specified.\n");
  printf("/join _channel_ : joins a channel on server.\n");
  printf("/part _channel_ : leave the channel.\n");
  printf("/users : display the users connected to the channel \
(display the nicknames of course).\n");
  printf("/msg nickname _message_ : sends a message to a specific user.\n");
  printf("_message_ : sends a message to all users connected to the channel.\n");
  return (R_SUCCESS);
}
