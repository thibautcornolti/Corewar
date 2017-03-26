/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Sun Mar 26 18:56:38 2017 Thibaut Cornolti
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"
#include "inst.h"

int		start_asm(char *name, int fd_s)
{
  int		fd_cor;
  t_header	header;
  char		*line;
  t_data	*list;
  t_label	*babybel;

  list = NULL;
  babybel = NULL;
  if ((fd_cor = get_fd_cor(name)) <= 0)
    return (84);
  if (pre_start_header(fd_s, &header) == 84)
    return (84);
  while ((line = skip_comm(fd_s)))
    {
      decrease_label(babybel, list);
      if ((get_info_line(my_epure_str(line), &list, &babybel)) == 84)
	return (84);
    }
  header.prog_size = get_prog_size(list);
  write_header(1/* fd_cor */, &header);
  write_data(1/* fd_cor */, list);
  close(fd_cor);
  return (0);
}

int		main(int ac, char **av)
{
  int		fd;

  (void)ac;(void)av;
  fd = open(av[1], O_RDONLY);
  if (start_asm(av[1], fd) == 84)
    return (84);
  return (0);
}
