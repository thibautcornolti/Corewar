/*
** alive.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 21:00:48 2017 Thibaut Cornolti
** Last update Thu Mar 30 21:37:17 2017 Thibaut Cornolti
*/

#include "vm.h"

int		check_end(t_champ *champ)
{
  t_ptr		*ptr;

  while (champ)
    {
      ptr = champ->chained_ptr;
      while (ptr)
	{
	  if (ptr->live >= CYCLE_TO_DIE)
	    return (0);
	  ptr = ptr->next;
	}
      champ = champ->next;
    }
  return (1);
}
