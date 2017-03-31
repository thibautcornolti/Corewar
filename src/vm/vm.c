/*
** vm.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 19:03:03 2017 Thibaut Cornolti
** Last update Fri Mar 31 13:45:42 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "my.h"
#include "vm.h"

static void	do_inst(t_map *map, t_champ *champ)
{
  t_ptr		*ptr;
  
  while (champ)
    {
      ptr = champ->chained_ptr;
      while (ptr)
	{
	  if (ptr->live >= CYCLE_TO_DIE)
	    continue ;
	  else if (map->arena[ptr->index_map % MEM_SIZE] == 0)
	    {
	      ptr->live += 1;
	      ptr->index_map += 1;
	      continue ;
	    }
	  translate(ptr, map);
	  ptr = ptr->next;
	}
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
  dprintf(2, "2:%d\n", champ->chained_ptr->index_map);
  write(1, arena.arena + champ->next->chained_ptr->index_map, 50);
  start_vm(&arena, champ);
  return (0);
}
