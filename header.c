/*
** header.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 14:19:52 2017 Luc
** Last update Mon Mar 20 13:57:46 2017 Thibaut Cornolti
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
  write_endian(fd, &(header->prog_size), sizeof(int));
  write(fd, header->comment, COMMENT_LENGTH + 1);
}

int		start_header(int fd_cor, char *file[2])
{
  t_header	header;

  my_memset(&header, 0, sizeof(t_header));
  if ((make_header(file, &header)) == 84)
    return (84);
  write_header(fd_cor, &header);
  return (0);
}
