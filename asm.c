/*
** asm.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:23:57 2017 Thibaut Cornolti
** Last update Tue Mar 21 13:46:54 2017 Thibaut Cornolti
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
  char		*line;

  if ((fd_cor = get_fd_cor(name)) <= 0)
    return (84);
  if (pre_start_header(fd_s, fd_cor) == 84)
    return (84);
  /* while ((line = skip_comm(fd_s))) */
  /*   nique_ta_race(my_epure_str(line), fd_cor); */
  return (0);
}

int		main(int ac, char **av)
{
  int		fd;

  (void)ac;(void)av;
  fd = open(av[1], O_RDONLY);

  if (start_asm(av[1], fd) == 84)
    return (84);
  
  t_arg oui = {T_DIR, 1};
  inst_live(&oui, 1);
  
  /* t_arg oui1 = {T_IND, 33}; */
  /* t_arg oui2 = {T_REG, 3}; */
  /* inst_ld(&oui1, &oui2, 1); */

  /* t_arg oui3 = {T_REG, 1}; */
  /* t_arg oui4 = {T_REG, 2}; */
  /* inst_st(&oui3, &oui4, 1); */

  /* t_arg oui5 = {T_REG, 2}; */
  /* t_arg oui6 = {T_IND, 56}; */
  /* inst_st(&oui5, &oui6, 1); */

  return (0);
}
