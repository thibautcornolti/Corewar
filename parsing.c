/*
** parsing.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 15:05:52 2017 Luc
** Last update Wed Mar  8 21:42:44 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"

int		give_me_the_name(char *name, t_champion *champ)
{
  int		i;
  int		j;
  char		dest[NAME_LENGTH];

  i = 5;
  while (name[i] != '"' && name[i] != '\0')
    i++;
  if (name[i] != '"')
    return (84);
  i++;
  j = 0;
  while (j <= NAME_LENGTH)
    dest[j++] = '\0';
  j = 0;
  while (name[i] != '"' && name[i] != '\0')
    dest[j++] = name[i++];
  if (name[i] != '"')
    return (84);
  write(champ->fd, dest, NAME_LENGTH + 4);
  return (0);
}

int		give_me_comment(char *comment, t_champion *champ)
{
  int		i;
  int		j;
  char		dest[2048];

  i = 8;
  while (comment[i] != '"' && comment[i] != '\0')
    i++;
  if (comment[i] != '"')
    return (84);
  i++;
  j = 0;
  while (comment[i] != '"' && comment[i] != '\0')
    dest[j++] = comment[i++];
  if (comment[i] != '"')
    return (84);
  while (j <= 2048)
    dest[j++] = '\0';
  write(champ->fd, dest, 2048);
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

int		make_header(t_champion *champ, char *path, int size)
{
  int		magic;
  char		*pathcor;

  if ((pathcor = file(path)) == NULL)
    return (84);
  if ((champ->fd = open(pathcor, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU |
			S_IRWXG | S_IRWXO)) == -1)
    return (84);
  champ->fd = 1;
  if ((my_strncmp(champ->champion[0], NAME_STRING, 5)) == 1)
    return (84);
  magic = MAGIC;
  write_endian(champ->fd, &magic, 4);
  if ((give_me_the_name(champ->champion[0], champ)) == 84)
    return (84);
  if ((my_strncmp(champ->champion[1], COMMENT_STRING, 8)) == 1)
    return (84);
  write_endian(champ->fd, &size, sizeof(int));
  if ((give_me_comment(champ->champion[1], champ)) == 84)
    return (84);
  return (0);
}
