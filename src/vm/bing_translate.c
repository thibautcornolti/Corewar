/*
** bing_translate.c for vm.h in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar 31 16:05:10 2017 Thibaut Cornolti
** Last update Sat Apr  1 16:39:15 2017 Thibaut Cornolti
*/

#include "vm.h"
#include "inst.h"

void			fill_arg_live(t_inst *inst,
				      t_map *map, t_ptr *ptr)
{
  int			j;

  j = -1;
  while (++j < 4)
    ((char *) (&(inst->arg[0].arg)))[j] =
      map->arena[(ptr->index_map + j) % MEM_SIZE];
  endian(&(inst->arg[0].arg), 4);
  ptr->index_map += 4;
  inst->arg[0].type = T_IND;
}

void			fill_arg_spec(t_inst *inst,
				      t_map *map, t_ptr *ptr)
{
  int			j;
  short			val;

  j = -1;
  val = 0;
  while (++j < 2)
    (char *) (&val)[j] = map->arena[(ptr->index_map + j) % MEM_SIZE];
  endian(&val, 2);
  inst->arg[0].arg = val;
  ptr->index_map += 2;
  inst->arg[0].type = T_IND;
}

void			redirect_inst(t_inst *inst,
				      t_map *map, t_ptr *ptr)
{
  static int	(*fct[16])(t_inst *, t_ptr *, t_map *) =
    {&live, &ld, &st, &add, &sub, &and, &or, &xor, &zjmp,
     &ldi, &sti, &ifork, &lld, &lld, &lfork, &aff};

  if ((unsigned char) inst->inst > 16)
    return ;
  fct[inst->inst - 1](inst, ptr, map);
}
