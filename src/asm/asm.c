/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Thu Mar 30 09:40:14 2017 Thibaut Cornolti
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"
#include "inst.h"

int		start_asm(char *name, int fd_s, t_label **babybel)
{
  int		fd_cor;
  t_header	header;
  char		*line;
  t_data	*list;

  list = NULL;
  if (pre_start_header(fd_s, &header) == 84)
    return (84);
  while ((line = skip_comm(fd_s)))
    {
      if ((get_info_line(my_epure_str(line),
			 &list, babybel, 0)) == 84)
	return (84);
    }
  header.prog_size = get_prog_size(list);
  if ((fd_cor = get_fd_cor(name)) <= 0)
    return (84);
  write_header(fd_cor, &header);
  write_data(fd_cor, list);
  close(fd_cor);
  return (0);
}

int		fill_label(int fd_s, t_label **babybel)
{
  t_header	header;
  char		*line;
  t_data	*list;

  list = NULL;
  if (pre_start_header(fd_s, &header) == 84)
    return (84);
  while ((line = skip_comm(fd_s)))
    if ((get_info_line(my_epure_str(line), &list, babybel, 1)) == 84)
      return (84);
  header.prog_size = get_prog_size(list);
  decrease_label_all(*babybel, list);
  return (0);
}

int		main(int ac, char **av)
{
  int		fd;
  t_label	*babybel;

  if (ac != 2)
    return (0);
  if ((fd = open(av[1], O_RDONLY)) <= 0)
    return (84);
  babybel = NULL;
  if (fill_label(fd, &babybel) == 84)
    return (84);
  close(fd);
  if ((fd = open(av[1], O_RDONLY)) <= 0)
    return (84);
  if (start_asm(av[1], fd, &babybel) == 84)
    return (84);
  close(fd);
  return (0);
}
