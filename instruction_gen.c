/*
** instruction_double.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 21:24:23 2017 Thibaut Cornolti
** Last update Tue Mar 21 11:49:19 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

int		inst_gen(char inst, t_arg args[4], int len, int fd)
{
  char		type;

  write(fd, &inst, 1);
  type = type_to_binary(args[0].type);
  type <<= 2;
  type += (len >= 2) ? type_to_binary(args[1].type) : 0;
  type <<= 2;
  type += (len >= 3) ? type_to_binary(args[2].type) : 0;
  type <<= 2;
  type += (len >= 4) ? type_to_binary(args[3].type) : 0;
  write(fd, &(type), 1);
  write_endian(fd, &(args[0].arg), type_to_size(args[0].type));
  if (len >= 2)
    write_endian(fd, &(args[1].arg), type_to_size(args[1].type));
  if (len >= 3)
    write_endian(fd, &(args[2].arg), type_to_size(args[2].type));
  if (len >= 4)
    write_endian(fd, &(args[3].arg), type_to_size(args[3].type));
  return (0);
}
