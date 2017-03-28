/*
** my_epure_str.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/lib/my
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Mon Mar 20 13:18:52 2017 Luc
** Last update Tue Mar 28 10:43:22 2017 Luc
*/

#include <stdlib.h>
#include "my.h"

char	*my_epure_str(char *str)
{
  int	i;
  int	j;
  char	*res;

  if (!str)
    return (str);
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (str);
  i = -1;
  while (str[++i])
    str[i] = (str[i] == '\t') ? ' ' : str[i];
  while (*str == ' ')
    str += 1;
  i = -1;
  j = -1;
  while (str[++i])
    {
      if (!(str[i] == ' ' && str[i + 1] == ' '))
	res[++j] = str[i];
    }
  res[++j] = 0;
  return (res);
}
