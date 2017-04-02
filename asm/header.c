/*
** header.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 14:19:52 2017 Luc
** Last update Sun Apr  2 12:03:31 2017 Bastien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

void		write_header(int fd, t_header *header)
{
  write_endian(fd, &(header->magic), sizeof(int));
  write(fd, header->prog_name, NAME_LENGTH + 1);
  write(fd, "\0\0\0", 3);
  write_endian(fd, &(header->prog_size), sizeof(int));
  write(fd, header->comment, COMMENT_LENGTH + 1);
  write(fd, "\0\0\0", 3);
}

static int	start_header(char *file[2], t_header *header)
{
  my_memset(header, 0, sizeof(t_header));
  if ((make_header(file, header)) == 84)
    return (84);
  return (0);
}

int		get_fd_cor(char *name)
{
  char		*pathcor;
  int		fd_cor;

  if ((pathcor = get_file(name)) == NULL)
    return (-1);
  if ((fd_cor = open(pathcor, O_RDWR | O_TRUNC | O_CREAT, 0664)) <= 0)
    return (-1);
  return (fd_cor);
}

int		pre_start_header(int fd_s, t_header *header)
{
  char		*file[2];

  if ((file[0] = my_epure_str(skip_comm(fd_s))) == NULL)
    return (84);
  if ((file[1] = my_epure_str(skip_comm(fd_s))) == NULL)
    return (84);
  if (start_header(file, header) == 84)
    return (84);
  return (0);
}
