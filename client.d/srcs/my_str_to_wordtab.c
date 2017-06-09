/*
** my_str_to_wordtab.c for  in /home/tran_w/Projects/myftp-2015s-2016-2017si-tran_w/my_server
** 
** Made by tran_w
** Login   <tran_w@epitech.net>
** 
** Started on  Sun Apr 14 22:27:21 2013 tran_w
** Last update Mon Jun  5 16:38:50 2017 Benjamin
*/

#include		<stdlib.h>

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
}

static int		is_separator(char c, char *sep)
{
  int			i;

  i = 0;
  if (c == 0)
    return (0);
  while (sep[i] != '\0')
    if (sep[i++] == c)
      return (42);
  return (0);
}

static int		count_words(const char *str, char *sep)
{
  int			i;
  int			wc;

  i = 0;
  wc = 0;
  if (!is_separator(str[i], sep))
    ++wc;
  while (str[i] != '\0')
    {
      if (is_separator(str[i], sep) && !is_separator(str[i + 1], sep))
        ++wc;
      ++i;
    }
  return (wc);
}

static char            *get_word(const char *str, int pos, int len)
{
  int			i;
  char			*res;

  i = 0;
  if ((res = malloc((len + 1) * sizeof(*res))) == NULL)
    return (NULL);
  while (i < len)
    res[i++] = str[pos++];
  res[i] = '\0';
  return (res);
}

char			**my_str_to_wordtab(const char *str, char *sep)
{
  char			**res;
  int			i;
  int			j;
  int			save;
  
  if ((res = malloc((count_words(str, sep) + 1) * sizeof(*res))) == NULL)
    return (NULL);
  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (!is_separator(str[i], sep))
        {
          save = i;
          while (str[i] != '\0' && !is_separator(str[i], sep))
	    ++i;
          if ((res[j++] = get_word(str, save, i - save)) == NULL)
	    return (NULL);
        }
      else
	++i;
    }
  res[j] = NULL;
  return (res);
}
