/*
** label.c for coreware in /home/rectoria/delivery/Projets/CPE_2016_corewar
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Sun Mar 26 15:14:06 2017 Bastien
** Last update Thu Mar 30 09:14:52 2017 Thibaut Cornolti
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

int	get_label_pos(char *name, t_label *label)
{
  t_label	*temp;

  temp = label;
  while (temp && my_strcmp(name, temp->lname) && temp->next)
    temp = temp->next;
  if (temp && !my_strcmp(name, temp->lname))
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
  while (temp && temp->lname && my_strcmp(fname, temp->lname)
	 && temp->next)
    temp = temp->next;
  if (temp && temp->lname && !my_strcmp(fname, temp->lname))
    return (84);
  new->lname = fname;
  temp->next = (new == temp) ? NULL : new;
  return (0);
}

int		check_good_label(char *label)
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

void		decrease_label(t_label *babybel, t_data *data)
{
  int		size;
  char		t;

  size = 1;
  if (!babybel || !data)
    return ;
  while (data->next)
    data = data->next;
  t = data->inst;
  if (t == 1)
    size += 4;
  else if (t == 9 || t == 12 || t == 15)
    size += 2;
  else
    size += get_type_size(t, data);
  babybel->lpos -= size;
  while (babybel->next)
    {
      babybel = babybel->next;
      babybel->lpos -= size;
    }
}

void		decrease_label_all(t_label *babybel, t_data *data)
{
  int		size;
  char		t;

  size = 0;
  if (!babybel || !data)
    return ;
  while (data)
    {
      size += 1;
      t = data->inst;
      if (t == 1)
	size += 4;
      else if (t == 9 || t == 12 || t == 15)
	size += 2;
      else
	size += get_type_size(t, data);
      data = data->next;
    }
  babybel->lpos += size;
  while (babybel->next)
    {
      babybel = babybel->next;
      babybel->lpos += size;
    }
}
