/*
** instruction_2.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:08:53 2017 Luc
** Last update Sun Apr  2 12:39:16 2017 Thibaut Cornolti
*/

#include "vm.h"

int	and(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	a;
  int	b;

  if (inst->inst != 0x06)
    return (84);
  if (!(inst->arg[0].type & (T_REG | T_DIR | T_IND)) ||
      !(inst->arg[1].type & (T_REG | T_DIR | T_IND)) ||
      !(inst->arg[2].type & T_REG))
    return (84);
  a = get_arg_value(&(inst->arg[0]), ptr, map);
  b = get_arg_value(&(inst->arg[0]), ptr, map);
  if ((unsigned int) inst->arg[2].arg >= REG_SIZE)
    return (0);
  ptr->father->reg[inst->arg[2].arg - 1] = a & b;
  ptr->carry = (a & b) ? 0 : 1;
  return (0);
}

int	or(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	a;
  int	b;

  if (inst->inst != 0x07)
    return (84);
  if (!(inst->arg[0].type & (T_REG | T_DIR | T_IND)) ||
      !(inst->arg[1].type & (T_REG | T_DIR | T_IND)) ||
      !(inst->arg[2].type & T_REG))
    return (84);
  a = get_arg_value(&(inst->arg[0]), ptr, map);
  b = get_arg_value(&(inst->arg[0]), ptr, map);
  if ((unsigned int) inst->arg[2].arg >= REG_SIZE)
    return (0);
  ptr->father->reg[inst->arg[2].arg - 1] = a | b;
  ptr->carry = (a | b) ? 0 : 1;
  return (0);
}

int	xor(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	a;
  int	b;

  if (inst->inst != 0x08)
    return (84);
  if (!(inst->arg[0].type & (T_REG | T_DIR | T_IND)) ||
      !(inst->arg[1].type & (T_REG | T_DIR | T_IND)) ||
      !(inst->arg[2].type & T_REG))
    return (84);
  a = get_arg_value(&(inst->arg[0]), ptr, map);
  b = get_arg_value(&(inst->arg[0]), ptr, map);
  if ((unsigned int) inst->arg[2].arg >= REG_SIZE)
    return (0);
  ptr->father->reg[inst->arg[2].arg - 1] = a ^ b;
  ptr->carry = (a ^ b) ? 0 : 1;
  return (0);
}

int	zjmp(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void) map;
  if (inst->inst != 0x09)
    return (84);
  if (!ptr->carry)
    return (0);
  ptr->index_map += inst->arg[0].arg;
  if (ptr->index_map < 0)
    ptr->index_map += MEM_SIZE;
  return (0);
}
