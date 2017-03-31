/*
** intruction.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 16:35:29 2017 Luc
** Last update Fri Mar 31 19:25:39 2017 Bastien
*/

#include <unistd.h>
#include "vm.h"
#include "my.h"

int		live(t_inst *inst, t_ptr *ptr, t_map *map)
{
  t_champ	*temp;
  
  (void)map;
  if (inst->inst != 0x01 || !(T_DIR & inst->arg[0].type))
    return (84);
  temp = ptr->father;
  while (temp->prev)
    temp = temp->prev;
  while (temp->next && temp->reg[0] != inst->arg[0].arg)
    temp = temp->next;
  if (!temp->next && temp->reg[0] != inst->arg[0].arg)
    return (84);
  temp->live = 0;
  write(1, "The player ", 11);
  my_put_nbr(inst->arg[0].arg);
  write(1, "(", 1);
  write(1, temp->name, my_strlen(temp->name));
  write(1, ") is alive.\n", 13);
  return (0);
}

int	ld(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x02 || !(T_REG & inst->arg[1].type) ||
      !(inst->arg[1].arg - 1) || inst->arg[1].arg - 1 > REG_NUMBER)
    return (84);
  if (inst->arg[0].type & T_IND)
    my_memncpy(&(ptr->father->reg[inst->arg[1].arg - 1]), map->arena +
	       (ptr->father->reg[0] + inst->arg[0].arg % IDX_MOD) % MEM_SIZE, 4);
  else if (inst->arg[0].type & T_DIR)
    my_memncpy(&(ptr->father->reg[inst->arg[1].arg - 1]), map->arena +
	       inst->arg[0].arg % MEM_SIZE, 4);
  else
    return (84);
  ptr->carry = (ptr->father->reg[inst->arg[1].arg - 1]) ? 0 : 1;
  return (0);
}

int	st(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x03 || !(inst->arg[0].type & T_REG) ||
      inst->arg[1].type & T_DIR || (unsigned int)inst->arg[0].arg < 16)
    return (84);
  if (inst->arg[1].type & T_REG && (unsigned int)inst->arg[1].arg < REG_NUMBER)
    {
      ptr->father->reg[inst->arg[0].arg - 1] = inst->arg[1].arg;
      return (0);
    }
  my_memncpy (map->arena + (ptr->father->reg[0] + inst->arg[1].arg % IDX_MOD) % MEM_SIZE,
	      &ptr->father->reg[inst->arg[0].arg - 1], 4);
  my_memncpy (map->color + (ptr->father->reg[0] + inst->arg[1].arg % IDX_MOD) % MEM_SIZE,
	      &ptr->father->color, 4);
  return (0);
}

int	add(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x04 || !(inst->arg[0].type & T_REG) || !(inst->arg[1].type & T_REG) ||
      !(inst->arg[2].type & T_REG) || !(inst->arg[2].arg - 1) ||
      inst->arg[0].arg - 1 > REG_NUMBER || inst->arg[1].arg - 1 > REG_NUMBER ||
      inst->arg[2].arg - 1 > REG_NUMBER)
    return (84);
  ptr->father->reg[inst->arg[2].arg - 1] = ptr->father->reg[inst->arg[0].arg - 1]
    + ptr->father->reg[inst->arg[1].arg - 1];
  ptr->carry = (ptr->father->reg[inst->arg[2].arg - 1]) ? 0 : 1;
  return (0);
}

int	sub(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x05 || !(inst->arg[0].type & T_REG) || !(inst->arg[1].type & T_REG) ||
      !(inst->arg[2].type & T_REG) || !(inst->arg[2].arg - 1) ||
      inst->arg[0].arg - 1 > REG_NUMBER || inst->arg[1].arg - 1 > REG_NUMBER ||
      inst->arg[2].arg - 1 > REG_NUMBER)
    return (84);
  ptr->father->reg[inst->arg[2].arg - 1] = ptr->father->reg[inst->arg[0].arg - 1]
    - ptr->father->reg[inst->arg[1].arg - 1];
  ptr->carry = (ptr->father->reg[inst->arg[2].arg - 1]) ? 0 : 1;
  return (0);
}
