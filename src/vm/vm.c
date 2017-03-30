/*
** vm.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 19:03:03 2017 Thibaut Cornolti
** Last update Thu Mar 30 19:06:49 2017 Thibaut Cornolti
*/

int		main(int ac, char **av)
{
  t_cmd		*champion;

  champion = NULL;
  if (argc < 4)
    return (84);
  if ((pars_cmd(&champion, av)) == 84)
    return (84);
  
}
