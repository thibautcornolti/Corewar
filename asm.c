/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Tue Mar 28 10:50:22 2017 Luc
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
  if ((fd_cor = get_fd_cor(name)) <= 0)
    return (84);
  if (pre_start_header(fd_s, &header) == 84)
    return (84);
  while ((line = skip_comm(fd_s)))
    {
      decrease_label(*babybel, list);
      if ((get_info_line(my_epure_str(line), &list, babybel, 0)) == 84)
	return (84);
    }
  header.prog_size = get_prog_size(list);
  write_header(1/* fd_cor */, &header);
  write_data(1/* fd_cor */, list);
  close(fd_cor);
  return (0);
}

int		fill_label(char *name, int fd_s, t_label **babybel)
{
  int		fd_cor;
  t_header	header;
  char		*line;
  t_data	*list;

  list = NULL;
  if ((fd_cor = get_fd_cor(name)) <= 0)
    return (84);
  if (pre_start_header(fd_s, &header) == 84)
    return (84);
  while ((line = skip_comm(fd_s)))
    {
      decrease_label(*babybel, list);
      if ((get_info_line(my_epure_str(line), &list, babybel, 1)) == 84)
	return (84);
    }
  header.prog_size = get_prog_size(list);
  close(fd_cor);
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
  if (fill_label(av[1], fd, &babybel) == 84)
    return (84);
  close(fd);
  if ((fd = open(av[1], O_RDONLY)) <= 0)
    return (84);
  if (start_asm(av[1], fd, &babybel) == 84)
    return (84);
  close(fd);
  return (0);
}
