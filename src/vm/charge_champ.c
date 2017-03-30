/*
** put_champion_in_the_string_arena_and_malloc_if_not_real.c for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:18:25 2017 Bastien
** Last update Thu Mar 30 16:08:23 2017 Bastien
*/

#include "vm.h"

static char	*my_revnstr(char *str, int length)
{
  int		count;
  char		temp;

  count = length;
  if (length > 1)
    {
      count = 0;
      while (count < length / 2)
	{
	  temp = str[count];
	  str[count] = str[length - count - 1];
	  str[length - count - 1] = temp;
	  count += 1;
	}
    }
  return (str);
}

int	check_magic(int *nbr)
{
  char	*str;

  str = nbr;
  my_revnstr(str, sizeof(int));
  nbr = str;
  if (*nbr != MAGIC)
    return (84);
  return (0);
}

char	*add_champ(char *arena, char *name, int rank)
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

void		load_champ(t_champ *champ, t_arena *arena, int fd, int rank)
{
  t_header	header;
  t_champ	*champ;

  if (fd <= 0)
    return (0);
  if (read(fd, &header, sizeof(t_header)) != sizeof(header))
    return (0);
  if ((check_magic(&header.magic)) == 84)
    return (84);
  add_champ(arena, my_strdup(header.prog_name), rank);
}
