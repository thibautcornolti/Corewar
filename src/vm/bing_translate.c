/*
** bing_translate.c for vm.h in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 31 16:05:10 2017 Thibaut Cornolti
** Last update Fri Mar 31 16:15:02 2017 Thibaut Cornolti
*/

#include "vm.h"

void		fill_arg_live(t_inst *inst, t_map *map, t_ptr *ptr)
{
  int		j;

  j = -1;
  while (++j < 4)
    ((char *) (&(inst->arg[0].arg)))[j] =
      map->arena[(ptr->index_map + j) % MEM_SIZE];
  endian(&(inst->arg[0].arg), 4);
  ptr->index_map += 4;
  inst->arg[0].type = T_IND;
  printf("live arg %d\n\n", inst->arg[0].arg);
}

void		redirect_inst(t_inst *inst, t_map *map, t_ptr *ptr)
{
  if (inst->inst == 0x01)
    live(inst, ptr, map);
}
