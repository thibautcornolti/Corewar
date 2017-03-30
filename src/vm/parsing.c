/*
** parsing.c for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 11:06:17 2017 Luc
** Last update Thu Mar 30 19:06:43 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"
#include "my.h"

static int	add_to_list(t_cmd **champ,
			    int prog_number, int load_adress,
			    char *prog_name)
{
  t_cmd		*tmp;
  t_cmd		*element;

  if ((element = malloc(sizeof(*element))) == NULL)
    return (84);
  element->prog_number = prog_number;
  element->load_adress = load_adress;
  element->prog_name = prog_name;
  element->next = NULL;
  if (*champ == NULL)
      *champ = element;
  else
    {
      tmp = *champ;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = element;
    }
  return (0);
}

static int	get_info_champ(char **argv, int *i, int *adress, int *num)
{
  if (my_strcmp(argv[*i], "-n") == 0)
    {
      if ((my_str_isnum(argv[*i + 1])) == 0)
	return (84);
      *num = my_getnbr(argv[*i + 1]);
      *i += 2;
    }
  if (my_strcmp(argv[*i], "-a") == 0)
    {
      if ((my_str_isnum(argv[*i + 1])) == 0)
	return (84);
      *adress = my_getnbr(argv[*i + 1]);
      *i += 2;
    }
  return (0);
}

int		pars_cmd(t_cmd **champ, char **argv)
{
  int		i;
  char		*name;
  int		num;
  int		adress;

  if ((my_str_isnum(argv[1])) != 1)
    return (84);
  i = 1;
  num = 1;
  adress = 0;
  while (argv[++i] != NULL)
    {
      if ((get_info_champ(argv, &i, &adress, &num)) == 84)
	return (84);
      if (my_strcmp(argv[i], "-a") == 1 && my_strcmp(argv[i], "-n") == 1)
      	{
	  name = argv[i];
      	  add_to_list(champ, num, adress, name);
	  num += 1;
      	}
    }
  return (0);
}
