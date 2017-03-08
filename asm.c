/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Wed Mar  8 21:23:28 2017 Thibaut Cornolti
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"

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
  /* int		fd; */

  (void)ac;(void)av;
  /* fd = open("oui", O_RDWR | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO); */
  inst_live(1, 1);

  t_arg oui1 = {T_IND, 33};
  t_arg oui2 = {T_REG, 3};
  inst_ld(&oui1, &oui2, 1);

  t_arg oui3 = {T_REG, 1};
  t_arg oui4 = {T_REG, 2};
  inst_st(&oui3, &oui4, 1);

  t_arg oui5 = {T_REG, 2};
  t_arg oui6 = {T_IND, 56};
  inst_st(&oui5, &oui6, 1);

  return (0);
}
