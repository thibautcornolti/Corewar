/*
** instruction.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 14:53:48 2017 Thibaut Cornolti
** Last update Tue Mar 21 14:12:03 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

int		inst_live(t_arg *first, int fd)
{
  char		inst;

  inst = 0x01;
  write(fd, &inst, 1);
  write_endian(fd, &(first->arg), 4);
  return (0);
}

int		inst_ld(t_arg *first, t_arg *second, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  return (inst_gen(0x02, args, 2, fd));
}

int		inst_st(t_arg *first, t_arg *second, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  return (inst_gen(0x03, args, 2, fd));
}

int		inst_add(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x04, args, 3, fd));
}

int		inst_sub(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x05, args, 3, fd));
}
