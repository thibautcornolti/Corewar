/*
** instruction_3.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:14:26 2017 Luc
** Last update Sat Apr  1 15:38:39 2017 Thibaut Cornolti
*/

#include "vm.h"

int	sti(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	temp1;
  int	temp2;

  if (inst->inst != 0x0b || !(inst->arg[0].type & T_REG) ||
      (unsigned int) inst->arg[0].arg > REG_NUMBER ||
      inst->arg[2].type & T_IND)
    return (84);
  temp1 = get_arg_value(inst->arg[1], ptr, map);
  temp2 = get_arg_value(inst->arg[1], ptr, map);
  map->arena[(ptr->index_map + (temp1 + temp2) % IDX_MOD) % MEM_SIZE] =
    ptr->father->reg[inst->arg[0].arg - 1];
  return (0);
}

int	ifork(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0c || !(inst->arg[0].type & T_DIR))
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	lld(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0d || inst->arg[0].type & T_REG ||
      !(inst->arg[1].type & T_REG))
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	lldi(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0e || inst->arg[1].type & T_IND ||
      !(inst->arg[2].type & T_REG))
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	lfork(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0f || !(inst->arg[0].type & T_DIR))
    return (84);
  (void)ptr;(void)map;
  return (0);
}
