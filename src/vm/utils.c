/*
** utils.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 31 17:49:39 2017 Thibaut Cornolti
** Last update Sat Apr  1 18:23:39 2017 Thibaut Cornolti
*/

#include "vm.h"

int		get_arg_value(t_arg *arg, t_ptr *ptr, t_map *map)
{
  int		res;

  if (arg->type == T_REG)
    {
      if ((unsigned int) arg->arg >= REG_SIZE)
	return (0);
      res = ptr->father->reg[arg->arg - 1];
    }
  else if (arg->type == T_DIR)
    res = arg->arg;
  else
    res = map->arena[(ptr->index_map +
		      arg->arg % IDX_MOD) % MEM_SIZE];
  return (res);
}
