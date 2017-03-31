/*
1;2802;0c** utils_translate.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 17:01:59 2017 Thibaut Cornolti
** Last update Fri Mar 31 11:32:05 2017 Thibaut Cornolti
*/

#include "vm.h"

void		my_memncpy(void *dest, void *src, int n)
{
  char		*dests;
  char		*srcs;
  int		i;

  dests = dest;
  srcs = src;
  i = -1;
  while (++i < n)
    dests[i] = srcs[i];
}

int		binary_to_type(char code)
{
  const char	type[3] = {T_REG, T_DIR, T_IND};
  int		i;

  i = -1;
  while (++i < 3)
    {
      if (code == i + 1)
	return (type[i]);
    }
  return (0);
}

int		inst_to_time(char inst)
{
  const int	time[17] = {0, 10, 5, 5, 10, 10, 6, 6, 6, 20,
			    25, 25, 800, 10, 50, 1000, 2};

  return (time[(int) inst]);
}

int		type_to_size(char inst, char type)
{
  const char    types[3] = {T_REG, T_DIR, T_IND};
  const char    size[3] = {1, 4, 2};
  int           i;

  if ((inst == 10 || inst == 11 || inst == 14) &&
      type == T_DIR)
    return (2);
  i = -1;
  while (++i < 3)
    if (types[i] == type)
      return (size[i]);
  return (0);
}
