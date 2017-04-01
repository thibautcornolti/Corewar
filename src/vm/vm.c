/*
** vm.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 19:03:03 2017 Thibaut Cornolti
** Last update Sat Apr  1 23:05:07 2017 Thibaut Cornolti
*/

#include <stdio.h>

#include <unistd.h>
#include "my.h"
#include "vm.h"

static void	do_inst(t_map *map, t_champ *champ)
{
  t_ptr		*ptr;

  while (champ)
    {
      ptr = champ->chained_ptr;
      if (ptr->father->live < CYCLE_TO_DIE)
	while (ptr)
	  {
	    if (ptr->cycle)
	      ptr->cycle -= 1;
	    else
	      translate(ptr, map);
	    ptr = ptr->next;
	  }
      champ->live += 1;
      champ = champ->next;
    }
}

int		start_vm(t_map *map, t_champ *champ)
{
  int		cycle;

  cycle = 0;
  while (get_nbr_live(champ) > 1)
    {
      do_inst(map, champ);
      cycle += 1;
    }
  my_putstr("The player ");
  my_put_nbr(get_last_live(champ)->color);
  my_putstr("(");
  my_putstr(get_last_live(champ)->name);
  my_putstr(")");
  my_putstr(" has won.\n");
  return (0);
}

int		main(int ac, char **av)
{
  t_cmd		*champ_cmd;
  t_champ	*champ;
  t_map		arena;

  champ_cmd = NULL;
  champ = NULL;
  my_memset(&arena, 0, sizeof(t_map));
  if (ac < 4)
    return (84);
  if ((pars_cmd(&champ_cmd, av)) == 84)
    return (84);
  while (champ_cmd)
    {
      champ = load_champ(champ, &arena, champ_cmd);
      champ_cmd = champ_cmd->next;
    }
  start_vm(&arena, champ);
  return (0);
}
