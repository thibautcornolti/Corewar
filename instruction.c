/*
** instruction.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 14:53:48 2017 Thibaut Cornolti
** Last update Wed Mar  8 21:26:45 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

void		inst_live(int player_number, int fd)
{
  char		inst;

  inst = 0x01;
  write(fd, &inst, 1);
  write_endian(fd, &player_number, 4);
}

void		inst_ld(t_arg *first_arg, t_arg *second_arg, int fd)
{
  inst_double(0x02, first_arg, second_arg, fd);
}

void		inst_st(t_arg *first_arg, t_arg *second_arg, int fd)
{
  inst_double(0x03, first_arg, second_arg, fd);
}
