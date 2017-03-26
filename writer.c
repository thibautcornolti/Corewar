/*
** writer.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Sun Mar 26 17:27:59 2017 Thibaut Cornolti
** Last update Sun Mar 26 19:08:57 2017 Thibaut Cornolti
*/

#include "asm.h"
#include "inst.h"

void		write_data(int fd_cor, t_data *data)
{
  const char	spec[5] = {0x01, 0x09, 0x0c, 0x0f, 0x00};

  while (data)
    {
      if (contains_char(data->inst, (char *) spec))
	inst_spec(data->inst, data->arg, fd_cor);
      else
	inst_gen(data->inst, data->arg, nbr_arg(data->inst), fd_cor);
      data = data->next;
    }
}
