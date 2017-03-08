/*
** instruction.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 14:53:48 2017 Thibaut Cornolti
** Last update Wed Mar  8 19:31:27 2017 Thibaut Cornolti
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
  char		inst;
  char		type;

  inst = 0x02;
  write(fd, &inst, 1);
  type = type_to_binary(first_arg->type);
  type <<= 2;
  type += type_to_binary(second_arg->type);
  type <<= 4;
  write(fd, &(type), 1);
  write_endian(fd, &(first_arg->arg), type_to_size(first_arg->type));
  write_endian(fd, &(second_arg->arg), type_to_size(second_arg->type));
}
