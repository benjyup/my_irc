/*
** commande_server.c for myirc in /home/jeanadrien/rendu/PROJECT/PSU_2016_myirc/src
** 
** Made by Jean-Adrien Domage
** Login   <jeanadrien.domage@epitech.eu>
** 
** Started on  Wed May 31 15:52:38 2017 Jean-Adrien Domage
** Last update Wed May 31 15:53:59 2017 Jean-Adrien Domage
*/

int	commande_server(int server_fd)
{
  struct sockaddr_in    client;
  socklen_t             client_size;

  client_size = sizeof(client);
  if (accept(fd, (struct sockaddr *)&client, &client_size) == -1)
    return (perror("accept()"), 84);
}
