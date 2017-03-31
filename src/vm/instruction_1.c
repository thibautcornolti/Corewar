/*
** intruction.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 16:35:29 2017 Luc
** Last update Fri Mar 31 14:51:22 2017 Thibaut Cornolti
*/

#include "vm.h"

int	live(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x01)
    return (84);
  return (0);
}

int	ld(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	registre;

  if (inst->inst != 0x02)
    return (84);
  return (0);
}

int	st(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x03)
    return (84);
  return (0);
}

int	add(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x04)
    return (84);
  return (0);
}

int	sub(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x05)
    return (84);
  return (0);
}
