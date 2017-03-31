/*
** intruction.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 16:35:29 2017 Luc
** Last update Fri Mar 31 17:37:33 2017 Bastien
*/

#include <unistd.h>
#include "vm.h"
#include "my.h"

int		live(t_inst *inst, t_ptr *ptr, t_map *map)
{
  t_champ	*temp;
  
  (void)map;
  if (inst->inst != 0x01)
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
  if (inst->inst != 0x02 || !inst->arg[1].arg || inst->arg[0].arg > REG_NUMBER)
    return (84);
  ptr->father->reg[inst->arg[1].arg - 1] =
    (int)my_strncpy(ptr->father->reg[0] + inst->arg[0].arg%IDX_MOD, 4);
  ptr->carry = (ptr->father->reg[inst->arg[1].arg - 1]) ? 0 : 1;
  return (0);
}

int	st(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x03)
    return (84);
  return (0);
}

int	add(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x04)
    return (84);
  return (0);
}

int	sub(t_inst *inst, t_ptr *ptr, t_map *map)
{
  (void)ptr;(void)map;
  if (inst->inst != 0x05)
    return (84);
  return (0);
}
