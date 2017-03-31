/*
** instruction_2.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:08:53 2017 Luc
** Last update Fri Mar 31 18:51:24 2017 Thibaut Cornolti
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
  if (inst->arg[2].arg >= 16)
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
  if (inst->arg[2].arg >= 16)
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
  if (inst->arg[2].arg >= 16)
    return (0);
  ptr->father->reg[inst->arg[2].arg - 1] = a ^ b;
  ptr->carry = (a ^ b) ? 0 : 1;
  return (0);
}

int	zjmp(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x09)
    return (84);
  if (!(inst->arg[0].type & T_DIR))
    return (0);
  if (!ptr->carry)
    return (0);
  ptr->index_map = inst->arg[0].arg;
  return (0);
}

int	ldi(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x0a)
    return (84);
  (void)ptr;(void)map;
  return (0);
}
