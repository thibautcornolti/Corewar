/*
** put_champion_in_the_string_arena_and_malloc_if_not_real.c for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:18:25 2017 Bastien
** Last update Thu Mar 30 21:15:16 2017 Bastien
*/

#include "vm.h"

int	check_magic(int *nbr)
{
  endian(nbr, sizeof(int));
  if (*nbr != MAGIC)
    return (84);
  return (0);
}

int		add_cmap(t_map *arena, t_champion *champ, t_cmd *cmd, int fd)
{
  static int	i = 0;
  char		c;
  int		j;

  j = i;
  while (++i < MEM_SIZE && write(fd, &c, 1))
    {
      arena[i] = c;
      color[i] = cmd->prog_number;
    }
  i -= 1;
  return (j);
}

void		add_champ(t_header *header, int pos, t_champ *champ, t_cmd *cmd)
{
  t_champ	*new;
  t_champ	*temp;
  t_ptr		*son;

  if ((new = malloc(sizeof(t_champ))) == 0)
    return ;
  new->name = my_strdup(&header->name);
  new->comment = my_strdup(&header->comment);
  my_memset(new->reg, 0, sizeof(int) * REG_SIZE);
  new-reg[0] = cmd->prog_number;
  new->next = 0;
  if ((son = malloc(sizeof(t_ptr))) == 0)
    return ;
  my_memset(son, 0, sizeof(t_ptr));
  son->father = new;
  son->index_map = pos;
  new->chained_ptr = son;
  temp = (champ) ? champ : new;
  while (temp->next != NULL)
    temp = temp->next;
  champ = (temp == new) ? new : champ;
  champ->next = (temp == new) ? 0 : new;
  return (champ);
}

void		load_champ(t_champ *champ, t_map *arena, t_cmd *cmd)
{
  t_header	header;
  int		fd;

  if ((fd = open(cmd->prog_name, O_RDONLY)) <= 0)
    return (0);
  if (read(fd, &header, sizeof(t_header)) != sizeof(header))
    return (0);
  if ((check_magic(&header.magic)) == 84)
    return (84);
  champ = add_champ(&header, add_cmap(arena, champ, cmd, fd), champ, cmd);
  return (champ)
}
