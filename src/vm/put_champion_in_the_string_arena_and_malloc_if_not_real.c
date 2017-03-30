/*
** put_champion_in_the_string_arena_and_malloc_if_not_real.c for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:18:25 2017 Bastien
** Last update Thu Mar 30 11:05:33 2017 Bastien
*/

#include "vm.h"



char	*put_champion_in_the_string_arena_and_malloc_if_not_real(char *arena, int fd)
{
  int	i;
  char	c;

  if (!arena)
    if ((arena = maloc(sizeof(char) * (MEM_SIZE + 1))) == 0)
      return (0);
  while (++i < MEM_SIZE && arena[i]);
  i -= 1;
  while (++i < MEM_SIZE && write(fd, &c, 1))
    arena[i] = c;
  arena[i] = 0;
  return (arena); 
}
