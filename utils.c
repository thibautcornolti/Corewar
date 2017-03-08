/*
** utils.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 18:24:31 2017 Thibaut Cornolti
** Last update Wed Mar  8 18:36:51 2017 Luc
*/

#include "asm.h"

char		type_to_binary(char type)
{
  const char	types[4] = {T_REG, T_DIR, T_IND, T_LAB};
  int		i;

  i = -1;
  while (++i < 4)
    if (types[i] == type)
      return (type + 1);
  return (0);
}

int		contains_char(char c, char *str)
{
  int		i;
  int		count;

  i = -1;
  count = 0;
  while (str[++i])
    if (c == str[i])
      count += 1;
  return (count);
}
