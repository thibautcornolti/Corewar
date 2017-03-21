/*
** instruction_next.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Mar 21 11:00:55 2017 Thibaut Cornolti
** Last update Tue Mar 21 11:28:22 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

int		inst_aff(t_arg *first, int fd)
{
  t_arg		args[4];

  args[0] = *first;
  return (inst_gen(0x10, args, 1, fd));
}
