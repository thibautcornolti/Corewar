/*
** header.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 14:19:52 2017 Luc
** Last update Mon Mar 20 13:08:25 2017 Thibaut Cornolti
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
    exit(84);
  while ((read(fd, &c, 1)) > 0)
    {
      if (c == '\n')
	(*line) += 1;
    }
  close(fd);
  return (0);
}

void		write_header(int fd, t_header *header)
{
  write_endian(fd, &(header->magic), sizeof(int));
  write(fd, header->prog_name, NAME_LENGTH + 1);
  write_endian(fd, &(header->prog_size), sizeof(int));
  write(fd, header->comment, COMMENT_LENGTH + 1);
}

int		start_header(char *champion, int fd)
{
  t_champion	chp;
  int		line;
  t_header	header;

  my_memset(&header, 0, sizeof(t_header));
  line = 0;
  take_info(champion, &line);
  if ((chp.champion = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (0);
  line = 0;
  while ((chp.champion[line] = get_next_line(fd)) != NULL)
    line++;
  if ((make_header(&chp, champion, &header)) == 84)
    return (84);
  write_header(chp.fd, &header);
  return (0);
}
