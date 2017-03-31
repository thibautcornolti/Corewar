/*
** instruction_3.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:14:26 2017 Luc
** Last update Fri Mar 31 14:50:37 2017 Thibaut Cornolti
*/

#include "vm.h"

int	sti(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0b)
    return (84);
  return (0);
}

int	fork(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0c)
    return (84);
  return (0);
}

int	lld(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0d)
    return (84);
  return (0);
}

int	lldi(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0e)
    return (84);
  return (0);
}

int	lfork(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0f)
    return (84);
  return (0);
}
