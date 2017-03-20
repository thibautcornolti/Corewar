/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Mon Mar 20 14:02:24 2017 Thibaut Cornolti
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "asm.h"

static int	get_fd_cor(char *name)
{
  char		*pathcor;
  int		fd_cor;

  if ((pathcor = get_file(name)) == NULL)
    return (-1);
  if ((fd_cor = open(pathcor, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU |
		     S_IRWXG | S_IRWXO)) <= 0)
    return (-1);
  return (fd_cor);
}

static int	start_asm(char *name, int fd_s)
{
  char		*file[2];
  int		fd_cor;

  if ((fd_cor = get_fd_cor(name)) <= 0)
    return (84);
  file[0] = my_epure_str(get_next_line(fd_s));
  file[1] = my_epure_str(get_next_line(fd_s));
  fd_cor = 1;
  if (start_header(fd_cor, file) == 84)
    return (84);
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
  inst_live(1, 1);

  t_arg oui1 = {T_IND, 33};
  t_arg oui2 = {T_REG, 3};
  inst_ld(&oui1, &oui2, 1);

  t_arg oui3 = {T_REG, 1};
  t_arg oui4 = {T_REG, 2};
  inst_st(&oui3, &oui4, 1);

  t_arg oui5 = {T_REG, 2};
  t_arg oui6 = {T_IND, 56};
  inst_st(&oui5, &oui6, 1);

  return (0);
}
