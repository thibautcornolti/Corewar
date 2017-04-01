/*
** instruction_4.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:14:26 2017 Luc
** Last update Sat Apr  1 15:26:06 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "vm.h"

int	aff(t_inst *inst, t_ptr *ptr, t_map *map)
{
  char	c;

  if (inst->inst != 0x10 || !(inst->arg[0].type & T_REG) ||
      (unsigned int)inst->arg[0].arg >= REG_NUMBER)
    return (84);
  (void)ptr;(void)map;
  c = ptr->father->reg[inst->arg[0].arg] % 256;
  write(1, &c, 1);
  write(1, "\n", 1);
  return (0);
}
