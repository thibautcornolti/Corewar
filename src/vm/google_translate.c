/*
** google_translate.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 16:21:36 2017 Thibaut Cornolti
** Last update Thu Mar 30 21:30:14 2017 Thibaut Cornolti
*/

#include <fcntl.h>
#include <unistd.h>
#include "vm.h"
#include "my.h"

static void	set_type(t_inst *inst, unsigned char code)
{
  code >>= 2;
  inst->arg[2].type = binary_to_type(code & 0x03);
  code >>= 2;
  inst->arg[1].type = binary_to_type(code & 0x03);
  code >>= 2;
  inst->arg[0].type = binary_to_type(code & 0x03);  
}

static int	fill_arg(t_inst *inst, const char *map)
{
  int		i;
  int		size;
  char		type_size;

  i = -1;
  size = 0;
  while (++i < 3)
    {
      type_size = type_to_size(inst->inst, inst->arg[i].type);
      my_memncpy((char *) &(inst->arg[i].arg),
		 (void *) map, type_size);
      endian(&(inst->arg[i].arg), type_size);
      map += type_size;
      size += type_size;
    }
  return (size);
}

int		translate(t_ptr *ptr, const char *map)
{
  t_inst	inst;
  int		size;

  my_memset(&inst, 0, sizeof(t_inst));
  inst.inst = map[ptr->index_map];
  set_type(&inst, map[ptr->index_map + 1]);
  size = 2;
  size += fill_arg(&inst, map + 2 + ptr->index_map);
  write(1, map, 9);
  ptr->index_map += size;
  return (0);
}
