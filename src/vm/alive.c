/*
** alive.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 21:00:48 2017 Thibaut Cornolti
** Last update Fri Mar 31 15:55:08 2017 Thibaut Cornolti
*/

#include "vm.h"

int		get_nbr_live(t_champ *champ)
{
  int		champ_live;

  champ_live = 0;
  while (champ)
    {
      if (champ->live < CYCLE_TO_DIE)
	champ_live += 1;
      champ = champ->next;
    }
  return (champ_live);
}
