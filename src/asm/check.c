/*
** check.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 10:09:02 2017 Thibaut Cornolti
** Last update Thu Mar 30 10:13:19 2017 Thibaut Cornolti
*/

#include "asm.h"
#include "my.h"

int		check_inst(t_data *data)
{
  while (data)
    {
      if (data->inst <= 0x0 || data->inst > 0x10)
	{
	  my_puterror("Incorrect instruction!\n");
	  return (84);
	}
      data = data->next;
    }
  return (0);
}
