/*
** parsing_reading_info.c for parsing_reading_info.c in /home/romain/delivery/CPE_2016_corewar
** 
** Made by Romain LANCIA
** Login   <romain.lancia@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 20 13:55:43 2017 Romain LANCIA
** Last update Thu Mar 30 09:22:20 2017 Thibaut Cornolti
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"

static void	my_memncpy(void *dest, void *src, int n)
{
  char		*dests;
  char		*srcs;
  int		i;

  dests = dest;
  srcs = src;
  i = -1;
  while (++i < n)
    dests[i] = srcs[i];
}

static void	my_put_in_list(t_data **list, char inst, t_arg arg[3])
{
  t_data	*elem;
  t_data	*tmp;

  if ((elem = malloc(sizeof(t_data))) == NULL)
    return ;
  tmp = *list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  elem->next = NULL;
  elem->inst = inst;
  my_memncpy(elem->arg, arg, sizeof(t_arg) * 3);
  if (tmp)
    tmp->next = elem;
  else
    *list = elem;
}

char	get_inst(char *s)
{
  const char	*insts[16] = {"live", "ld", "st", "add",
			     "sub", "and", "or", "xor",
			     "zjmp", "ldi", "sti", "fork",
			     "lld", "lldi", "lfork", "aff"};
  int		i;

  i = -1;
  if (!s)
    return (0);
  while (++i < 16)
    if (!my_strcmp(s, (char *) insts[i]))
      return (i + 1);
  return (0);
}

static int	check_label(char *lname, t_label **babybel, int fill)
{
  if (get_inst(lname))
    return (0);
  lname[my_strlen(lname) - 1] = 0;
  if (check_good_label(lname))
    {
      if (!fill)
	return (1);
      else if ((label(my_strdup(lname), babybel)) == 84)
	{
	  my_puterror(lname);
	  exit(0 + my_puterror(": Multiple definition \
of the same label.\n"));
	}
      else
	return (1);
    }
  return (0);
}

int		get_info_line(char *line, t_data **list,
			      t_label **babybel, int fill)
{
  int		i;
  int		t;
  char		**tab;
  t_arg		arg[3];

  my_memset(arg, 0, sizeof(t_arg) * 3);
  if (!line || !line[0])
    return (0);
  tab = my_strsplit(line, " ,\t");
  i = 1;
  tab += check_label(tab[0], babybel, fill);
  if (!*tab)
    return (0);
  while (tab[i] != NULL)
    {
      arg[i - 1].type = verify_type_arg(tab[i], &t, *babybel);
      arg[i - 1].arg = t;
      i++;
    }
  my_put_in_list(list, get_inst(tab[0]), arg);
  decrease_label(*babybel, *list);
  return (0);
}
