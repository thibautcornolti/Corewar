/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Wed Mar  8 14:12:46 2017 Thibaut Cornolti
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"

void		write_endian(int fd, void *ptr, int size)
{
  int		i;

  i = -1;
  (void)i;
  //while (++i < size)
  write(fd, ptr, size);
}

void		inst(int type, int arg1, int arg2, int fd)
{
  write_endian(fd, &type, 1);
  write_endian(fd, &arg1, 4);
  write_endian(fd, &arg2, 4);
}

void		put(char *str, int fd)
{
  int		len;
  char		type;

  len = my_strlen(str);
  type = 4;
  write_endian(fd, &type, 1);
  write_endian(fd, &len, 4);
  write_endian(fd, str, len);
}

int		main(int ac, char **av)
{
  int		fd;

  (void)ac;(void)av;
  fd = open("oui", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
  
  inst(1, 17891, 21, fd);
  inst(1, 59, 1, fd);
  inst(2, 21, 10, fd);
  put("Yolo!!!!!", fd);
  return (0);
}
