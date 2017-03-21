/*
** instruction_next.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Mar 21 11:00:55 2017 Thibaut Cornolti
** Last update Tue Mar 21 14:14:59 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

int		inst_sti(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x0b, args, 3, fd));
}

int		inst_fork(t_arg *first, int fd)
{
  char		inst;

  inst = 0x0c;
  write(fd, &inst, 1);
  write_endian(fd, &(first->arg), 4);
  return (0);
}

int		inst_lld(t_arg *first, t_arg *second, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  return (inst_gen(0x0d, args, 2, fd));
}

int		inst_lldi(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x0e, args, 3, fd));
}

int		inst_lfork(t_arg *first, int fd)
{
  char		inst;

  inst = 0x0f;
  write(fd, &inst, 1);
  write_endian(fd, &(first->arg), 4);
  return (0);
}
