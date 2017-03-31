/*
** alive.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 21:00:48 2017 Thibaut Cornolti
** Last update Fri Mar 31 12:53:10 2017 Thibaut Cornolti
*/

#include "vm.h"

int		get_nbr_live(t_champ *champ)
{
  t_ptr		*ptr;
  int		champ_live;
  int		ptr_live;

  champ_live = 0;
  while (champ)
    {
      ptr_live = 0;
      ptr = champ->chained_ptr;
      while (ptr)
	{
	  if (ptr->live < CYCLE_TO_DIE)
	    ptr_live += 1;
	  ptr = ptr->next;
	}
      if (ptr_live)
	champ_live += 1;
      champ = champ->next;
    }
  return (champ_live);
}
