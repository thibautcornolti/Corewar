/*
** instruction_4.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 17:14:26 2017 Luc
** Last update Fri Mar 31 14:56:33 2017 Thibaut Cornolti
*/

#include "vm.h"

int	aff(t_inst *inst, t_ptr *ptr, t_map *map)
{
  if (inst->inst != 0x10)
    return (84);
  return (0);
}
