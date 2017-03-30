/*
** utils.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 18:24:31 2017 Thibaut Cornolti
** Last update Thu Mar 30 17:45:23 2017 Thibaut Cornolti
*/

#include "asm.h"
#include "my.h"

char		*skip_comm(int fd)
{
  char		*res;

  while ((res = get_next_line(fd)))
    if (res[0] != COMMENT_CHAR && res[0])
      return (res);
  return (res);
}

char		type_to_binary(char type)
{
  const char	types[3] = {T_REG, T_DIR, T_IND};
  int		i;

  i = -1;
  while (++i < 3)
    if (types[i] == type)
      return (i + 1);
  return (0);
}

char		type_to_size(char inst, char type)
{
  const char	types[4] = {T_REG, T_DIR, T_IND};
  const char	size[4] = {1, 4, 2};
  int		i;

  if ((inst == 10 || inst == 11 || inst == 14) &&
      type == T_DIR)
    return (2);
  i = -1;
  while (++i < 4)
    if (types[i] == type)
      return (size[i]);
  return (0);
}

int		nbr_arg(char inst)
{
  const char	args[17] = {0, 1, 2, 2, 3, 3, 3, 3, 3,
			    1, 3, 3, 1, 2, 3, 1, 1};
  return (args[(int) inst]);
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
