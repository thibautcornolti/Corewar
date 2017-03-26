/*
** label.c for coreware in /home/rectoria/delivery/Projets/CPE_2016_corewar
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Sun Mar 26 15:14:06 2017 Bastien
** Last update Sun Mar 26 17:50:49 2017 Thibaut Cornolti
*/

#include "my.h"
#include "asm.h"
#include <stdlib.h>

int	get_label_pos(char *name, t_label *label)
{
  t_label	*temp;

  temp = label;
  while (temp && my_strncmp(name, temp->lname, my_strlen(name)) && temp->next)
    temp = temp->next;
  if (!my_strncmp(name, temp->lname, my_strlen(name)))
    return (temp->lpos);
  return (84);
}

int		label(char *fname, t_label **label)
{
  t_label	*temp;
  t_label	*new;

  if ((new = malloc(sizeof(t_label))) == 0)
    return (84);
  my_memset(new, 0, sizeof(t_label));
  *label = (*label) ? *label : new;
  temp = *label;
  while (temp && temp->lname && my_strncmp(fname, temp->lname, my_strlen(fname))
	 && temp->next)
    temp = temp->next;
  if (temp && temp->lname && !my_strncmp(fname, temp->lname, my_strlen(fname)))
    return (84);
  new->lname = fname;
  temp->next = (new == temp) ? NULL : new;
  return (0);
}

int	check_good_label(char *label)
{
  int	i;

  i = 0;
  while(label[i] != '\0')
    {
      if (!contains_char(label[i], LABEL_CHARS))
	return (0);
      i++;
    }
  return (1);
}
