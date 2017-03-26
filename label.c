/*
** label.c for coreware in /home/rectoria/delivery/Projets/CPE_2016_corewar
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Sun Mar 26 15:14:06 2017 Bastien
** Last update Sun Mar 26 15:44:53 2017 Bastien
*/

#include "my.h"

int	get_label_pos(char *name, t_label *label)
{
  t_label	*temp;

  while (temp && my_strncmp(name, temp->lname, my_strlen(name)) && temp->next)
    temp = temp->next;
  if (!my_strncmp(name, temp->lname, my_strlen(name)))
    return (temp->lpos);
  return (84);
}

int		*label(char *fname, t_label **label)
{
  t_label	*temp;
  t_label	*new;

  temp = *label;
  if ((new = malloc(sizeof(t_label))) == 0)
    return (84);
  my_memset(new, 0, sizeof(t_label));
  while (temp && my_strncmp(fname, temp->lname, my_strlen(fname))
	 && temp->next)
    temp = temp->next;
  if (temp && !my_strncmp(fname, temp->lname, my_strlen(fname)))
    return (84);
  *label = (*label) ? *label : new;
  new->lname = fname;
  *temp->next = (*label = temp) ? 0 : new;
  return (0);
}
