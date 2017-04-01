/*
** instruction_3.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:14:26 2017 Luc
** Last update Sat Apr  1 21:56:31 2017 Thibaut Cornolti
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
  map->arena[(ptr->index_map + (temp1 + temp2) % IDX_MOD) % MEM_SIZE] =
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
  new->index_map = inst->arg[0].arg % IDX_MOD;
  if (new->index_map < 0)
    new->index_map += MEM_SIZE;
  new->cycle = inst_to_time(inst->inst);
  new->carry = 1;
  ptr->next = new;
  new->next = NULL;
  return (0);
}

int	lld(t_inst *inst, t_ptr *ptr, t_map *map)
{
  int	temp;

  if (inst->inst != 0x02 || !(T_REG & inst->arg[1].type) ||
      inst->arg[1].arg > REG_NUMBER)
    return (84);
  temp = get_larg_value(&inst->arg[0], ptr, map);
  ptr->father->reg[inst->arg[1].arg - 1] = temp;
  ptr->carry = (ptr->father->reg[inst->arg[1].arg - 1]) ? 0 : 1;
  return (0);
}

int	lfork(t_inst *inst, t_ptr *ptr, t_map *map)
{
  t_ptr	*new;

  (void) map;
  if (inst->inst != 0x0f)
    return (84);
  if ((new = malloc(sizeof(t_ptr))) == NULL)
    return (84);
  my_memset(new, 0, sizeof(t_ptr));
  new->father = ptr->father;
  new->index_map = inst->arg[0].arg;
  if (new->index_map < 0)
    new->index_map += MEM_SIZE;
  new->cycle = inst_to_time(inst->inst);
  new->carry = 1;
  ptr->next = new;
  new->next = NULL;
  return (0);
}
