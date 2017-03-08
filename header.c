/*
** header.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 14:19:52 2017 Luc
** Last update Wed Mar  8 18:18:45 2017 Luc
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

int		take_info(char *path, int *line)
{
  char		c;
  int		fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (0);
  while ((read(fd, &c, 1)) > 0)
    {
      if (c == '\n')
	(*line) += 1;
    }
  close(fd);
  return (0);
}

int		start_corewar(char *champion)
{
  t_champion	chp;
  int		line;
  int		fd;
  
  if ((fd = open(champion, O_RDONLY)) == -1)
    return (0);
  line = 0;
  take_info(champion, &line);
  if ((chp.champion = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (0);
  line = 0;
  while ((chp.champion[line] = get_next_line(fd)) != NULL)
    line++;
  if ((make_header(&chp, champion, 0)) == 84)
    return (84);
  close(fd);
  return (0);
}

int		main(int ac, char **av)
{
  (void)ac;(void)av;
  if (ac != 2)
    return (84);
  if ((start_corewar(av[1])) == 84)
    return (84);
  return (0);
}

