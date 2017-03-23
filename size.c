/*
** size.c for asm in /home/romain/delivery/CPE_2016_corewar
** 
** Made by Romain LANCIA
** Login   <romain.lancia@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 23:29:46 2017 Romain LANCIA
** Last update Thu Mar 23 23:54:04 2017 Romain LANCIA
*/

#include "asm.h"

static int	get_type_size(char t, t_data *list)
{
  int		size;
  int		i;

  size = 1;
  i = -1;
  while (++i < nbr_arg(t))
    {
      if (list->arg[i].type == T_DIR &&
	  (t == 10 || t == 11 || t == 13))
	size += 4;
      else
	size += type_to_size(list->arg[i].type);
    }
  return (size);
}

int		get_prog_size(t_data *list)
{
  int		size;
  char		t;

  size = 0;
  while (list)
    {
      size += 1;
      t = list->inst;
      if (t == 1 || t == 12 || t == 15 || t == 16)
	size += 4;
      else
        size += get_type_size(t, list);
      list = list->next;
    }
  return (size);
}
