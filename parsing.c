/*
** parsing.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 15:05:52 2017 Luc
** Last update Mon Mar 20 12:59:20 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"

int		give_me_the_name(char *name, t_header *header)
{
  int		i;
  int		j;

  i = 5;
  while (name[i] != '"' && name[i] != '\0')
    i++;
  if (name[i] != '"')
    return (84);
  i++;
  j = 0;
  while (name[i] != '"' && name[i] != '\0' && i <= NAME_LENGTH)
    header->prog_name[j++] = name[i++];
  if (name[i] != '"')
    return (84);
  return (0);
}

int		give_me_comment(char *comment, t_header *header)
{
  int		i;
  int		j;

  i = 8;
  while (comment[i] != '"' && comment[i] != '\0')
    i++;
  if (comment[i] != '"')
    return (84);
  i++;
  j = 0;
  while (comment[i] != '"' && comment[i] != '\0' && i <= NAME_LENGTH)
    header->comment[j++] = comment[i++];
  if (comment[i] != '"')
    return (84);
  return (0);
}

char		*get_the_name_of_file(char *path, int i)
{
  int		count;
  char		*dest;
  int		j;

  count = 0;
  while (count != i)
    {
      if ((*path) == '/')
	count += 1;
      path += 1;
    }
  j = 0;
  if ((dest = malloc(sizeof(char) * my_strlen(path) + 1)) == NULL)
    return (NULL);
  while (path[j] != '\0' && path[j] != '.')
    {
      dest[j] = path[j];
      j++;
    }
  if (path[j] != '.')
    return (NULL);
  dest[j] = '\0';
  return (my_strcat(dest,".cor"));
}

char		*file(char *path)
{
  int		i;
  char		*dest;

  i = 0;
  if ((i = contains_char('/', path)) > 0)
    return (get_the_name_of_file(path, i));
  if ((dest = malloc(sizeof(char) * my_strlen(path) + 5)) == NULL)
    return (NULL);
  while (path[i] != '\0' && path[i] != '.')
    {
      dest[i] = path[i];
      i += 1;
    }
  dest[i] = '\0';
  if (path[i] != '.')
    return (NULL);
  return (my_strcat(dest,".cor"));
}

int		make_header(t_champion *champ, char *path, t_header *header)
{
  char		*pathcor;

  if ((pathcor = file(path)) == NULL)
    return (84);
  if ((champ->fd = open(pathcor, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU |
			S_IRWXG | S_IRWXO)) == -1)
    return (84);
  champ->fd = 1;
  if ((my_strncmp(champ->champion[0], NAME_STRING, 5)) == 1)
    return (84);
  header->magic = MAGIC;
  if ((give_me_the_name(champ->champion[0], header)) == 84)
    return (84);
  if ((my_strncmp(champ->champion[1], COMMENT_STRING, 8)) == 1)
    return (84);
  if ((give_me_comment(champ->champion[1], header)) == 84)
    return (84);
  return (0);
}
