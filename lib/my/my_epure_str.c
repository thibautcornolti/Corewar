/*
** my_epure_str.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/lib/my
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Mon Mar 20 13:18:52 2017 Luc
** Last update Mon Mar 20 13:20:35 2017 Luc
*/

#include "my.h"

char	*my_epure_str(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while (str[i] == ' ' && str[i] != '\0')
    {
      str[i] = '\0';
      i = i - 1;
    }
  while (*str == ' ' && *str != '\0')
    str = str + 1;
  return (str);
}
