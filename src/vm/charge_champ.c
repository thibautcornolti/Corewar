/*
** put_champion_in_the_string_arena_and_malloc_if_not_real.c for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:18:25 2017 Bastien
** Last update Fri Mar 31 14:56:45 2017 Bastien
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "vm.h"

int		check_magic(int *nbr)
{
  endian(nbr, sizeof(int));
  if (*nbr != MAGIC)
    return (84);
  return (0);
}

int		add_cmap(t_map *arena, t_cmd *cmd, int fd)
{
  static int	i = -1;
  char		c;
  int		j;

  j = i + 1;
  while (++i < MEM_SIZE && read(fd, &c, 1))
    {
      arena->arena[i] = c;
      arena->color[i] = cmd->prog_number;
    }
  return (j);
}

t_champ		*add_champ(t_header *header, int pos, t_champ *champ, t_cmd *cmd)
{
  t_champ	*new;
  t_champ	*temp;
  t_ptr		*son;

  if ((new = malloc(sizeof(t_champ))) == NULL)
    return (NULL);
  new->name = my_strdup(header->prog_name);
  new->comment = my_strdup(header->comment);
  my_memset(new->reg, 0, sizeof(int) * REG_SIZE);
  new->reg[0] = cmd->prog_number;
  new->next = 0;
  if ((son = malloc(sizeof(t_ptr))) == NULL)
    return (NULL);
  my_memset(son, 0, sizeof(t_ptr));
  son->father = new;
  son->index_map = pos;
  new->chained_ptr = son;
  temp = (champ) ? champ : new;
  while (temp->next != NULL)
    temp = temp->next;
  champ = (temp == new) ? new : champ;
  champ->next = (temp == new) ? 0 : new;
  new->prev = champ;
  return (champ);
}

t_champ		*load_champ(t_champ *champ, t_map *arena, t_cmd *cmd)
{
  t_header	header;
  int		fd;

  if ((fd = open(cmd->prog_name, O_RDONLY)) <= 0)
    return (NULL);
  if (read(fd, &header, sizeof(t_header)) != sizeof(header))
    return (NULL);
  if ((check_magic(&header.magic)) == 84)
    return (NULL);
  if ((champ = add_champ(&header, add_cmap(arena, cmd, fd), champ, cmd)) == NULL)
    return (NULL);
  return (champ);
}
