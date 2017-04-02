/*
** instruction_3.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:14:26 2017 Luc
** Last update Sun Apr  2 12:50:08 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "vm.h"
#include "my.h"

int	sti(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	temp1;
  int	temp2;

  if (inst->inst != 0x0b || !(inst->arg[0].type & T_REG) ||
      (unsigned int) inst->arg[0].arg > REG_NUMBER ||
      inst->arg[2].type & T_IND)
    return (84);
  temp1 = get_arg_value(&(inst->arg[1]), ptr, map);
  temp2 = get_arg_value(&(inst->arg[1]), ptr, map);
  map->arena[(ptr->index_map + temp1 + temp2) % MEM_SIZE] =
    ptr->father->reg[inst->arg[0].arg - 1];
  return (0);
}

int	ifork(t_inst *inst, t_ptr *ptr, t_map *map)
{
  t_ptr	*new;

  (void) map;
  if (inst->inst != 0x0c)
    return (84);
  if ((new = malloc(sizeof(t_ptr))) == NULL)
    return (84);
  my_memset(new, 0, sizeof(t_ptr));
  new->father = ptr->father;
  new->index_map = ptr->index_map + inst->arg[0].arg;
  if (new->index_map < 0)
    new->index_map += MEM_SIZE;
  new->cycle = inst_to_time(inst->inst);
  new->carry = 1;
  ptr->next = new;
  new->next = NULL;
  return (0);
}

int	ldi(t_inst *inst, t_ptr *ptr, t_map *map)
{
  short	nb;

  (void) map;
  if (inst->inst != 0x0a || inst->arg[1].type & T_IND ||
      !(inst->arg[2].type & T_REG) ||
      (unsigned int)inst->arg[2].arg > REG_SIZE
      || (inst->arg[0].type & T_REG &&
	  (unsigned int)inst->arg[0].arg > 16))
    return (84);
  nb = get_arg_value(&inst->arg[0], ptr, map);
  nb += get_arg_value(&(inst->arg[1]), ptr, map);
  my_memncpy(&ptr->father->reg[inst->arg[2].arg - 1],
	     &(map->arena[ptr->index_map + nb]), 4);
  ptr->carry = (ptr->father->reg[inst->arg[2].arg - 1]) ? 0 : 1;
  return (0);
}
