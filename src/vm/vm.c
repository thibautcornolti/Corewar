/*
** vm.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 19:03:03 2017 Thibaut Cornolti
** Last update Thu Mar 30 22:04:02 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "my.h"
#include "vm.h"

int		start_vm(t_map *map, t_champ *champ)
{
  int		cycle;

  cycle = 0;
  while (check_end(champ))
    {

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
  start_vm(&arena, champ);
  return (0);
}
