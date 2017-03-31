/*
** instruction_2.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:08:53 2017 Luc
** Last update Fri Mar 31 15:54:22 2017 Thibaut Cornolti
*/

#include "vm.h"

int	and(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x06)
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	or(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x07)
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	xor(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x08)
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	zjmp(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x09)
    return (84);
  (void)ptr;(void)map;
  return (0);
}

int	ldi(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0a)
    return (84);
  (void)ptr;(void)map;
  return (0);
}
