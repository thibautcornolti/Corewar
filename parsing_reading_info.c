/*
** parsing_reading_info.c for parsing_reading_info.c in /home/romain/delivery/CPE_2016_corewar
** 
** Made by Romain LANCIA
** Login   <romain.lancia@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 20 13:55:43 2017 Romain LANCIA
** Last update Tue Mar 21 12:50:27 2017 Romain LANCIA
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"

int	get_info_line(char *line, int fd)
{
  int	i;
  int	j;
  int	t;
  char	**tab;
  t_arg arg[3];
  
  tab = my_strsplit(line, " ,");
  i = 1;
  while (tab[i] != NULL)
    {
      j = verify_type_arg(tab[i], &t);
      if (j == 1)
	{
	  arg[i - 1].type = T_DIR + '0';
	  arg[i - 1].arg = t;
	}
      if (j == 2)
	{
	  arg[i - 1].type = T_REG + '0';
	  arg[i - 1].arg = t;
	}
      if (j == 3)
	{
	  arg[i - 1].type = T_IND + '0';
	  arg[i - 1].arg = t;
	}
      i++;
    }
  printf("%c | %d\n", arg[0].type, arg[0].arg);
  printf("%c | %d\n", arg[1].type, arg[1].arg);
  return (0);
}

int	main(int ac, char **av)
{
  get_info_line(av[1], 0);
  return (0);
}
