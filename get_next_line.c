/*
** get_next_line2.c for get_next_line in /home/rectoria/delivery/Projets/PSU_2016_minishell2
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 16 09:38:18 2017 Bastien
** Last update Thu Mar 16 09:55:03 2017 Bastien
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*my_addstring(char *str, char c)
{
  char	*new;
  int	i;
  int	j;

  i = -1;
  j = my_strlen(str);
  if ((new = malloc(sizeof(char) * (j + 2))) == NULL)
    return (NULL);
  while (++i < j)
    new[i] = str[i];
  new[i] = c;
  new[i + 1] = 0;
  free(str);
  return (new);
}

char	*get_next_line(int fd)
{
  char	c;
  char	*str;

  str = NULL;
  while (fd >= 0 && read(fd, &c, 1) > 0 && (c != '\n' && c!= '\0'))
    str = my_addstring(str, c);
  return (str);
}
