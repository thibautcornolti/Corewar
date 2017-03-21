/*
** instruction_next.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Mar 21 11:00:55 2017 Thibaut Cornolti
** Last update Tue Mar 21 14:14:02 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

int		inst_and(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x06, args, 3, fd));
}

int		inst_or(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x07, args, 3, fd));
}

int		inst_xor(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x08, args, 3, fd));
}

int		inst_zjmp(t_arg *first, int fd)
{
  char		inst;

  inst = 0x09;
  write(fd, &inst, 1);
  write_endian(fd, &(first->arg), 4);
  return (0);
}

int		inst_ldi(t_arg *first, t_arg *second, t_arg *third, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  args[1] = *second;
  args[2] = *third;
  return (inst_gen(0x0a, args, 3, fd));
}
