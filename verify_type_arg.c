/*
** verify_type_arg.c for verify_type_arg.c in /home/romain/delivery/CPE_2016_corewar
** 
** Made by Romain LANCIA
** Login   <romain.lancia@epitech.eu@epitech.net>
** 
** Started on  Tue Mar 21 10:23:56 2017 Romain LANCIA
** Last update Sun Mar 26 15:47:09 2017 Luc
*/

#include <stdio.h>
#include "asm.h"
#include "my.h"

int     is_it_a_direct_arg(char *arg, int *nb)
{
  int   i;
  
  i = 0 + 0 * (*nb = 0);
  if (arg[0] != '%')
    return (0);
  else
    arg += 1; 
  while (arg[i] != '\0')
    {
      if (arg[i] < '0' || arg[i] > '9')
  	return (0);
      i++;
    }
  *nb = my_getnbr(arg);
  return (1);
}

int	is_it_a_label_arg(char *arg, int *nb, t_label *babybel)
{
  if ((get_inst(arg)) == 0)
    {
      *nb = get_label_pos(arg, babybel);
      return (1);
    }
  return (0);
}

int     is_it_a_register_arg(char *arg, int *nb)
{
  int   i;
  
  i = 0 + 0 * (*nb = 0);
  if (arg[0] != 'r')
    return (0);
  else
    arg += 1;
  while (arg[i] != '\0')
    {
      if (arg[i] < '0' || arg[i] > '9')
  	return (0);
      i++;
    }
  *nb = my_getnbr(arg);
  return (1);
}

int	is_it_a_indirect_arg(char *arg, int *nb)
{
  int   i;
  
  i = 0 + 0 * (*nb = 0);
  while (arg[i] != '\0')
    {
      if (arg[i] < '0' || arg[i] > '9')
  	return (0);
      i++;
    }
  *nb = my_getnbr(arg);
  return (1);
}

int     verify_type_arg(char *str, int *i, t_label **babybel)
{
  int	nb;
  int	ret;
  
  *i = 0;
  ret = 0;
  if (is_it_a_direct_arg(str, &nb) == 1)
    ret = T_DIR;
  else if (is_it_a_register_arg(str, &nb) == 1)
    ret = T_REG;
  else if (is_it_a_indirect_arg(str, &nb) == 1)
    ret = T_IND;
  else if (is_it_a_label_arg(str, &nb, *babybel) == 1)
    ret = T_DIR;
  else
    return (84);
  *i = nb;
  return (ret);
}

