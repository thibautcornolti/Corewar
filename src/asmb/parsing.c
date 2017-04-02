/*
** parsing.c for emacs in /home/sankamille/delivery/CPE_2016_corewar
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Wed Mar  8 15:05:52 2017 Luc
** Last update Sun Apr  2 12:09:27 2017 Thibaut Cornolti
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
  if (!(name[i] == '"' && !name[i + 1]))
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
  if (!(comment[i] == '"' && !comment[i + 1]))
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
  if ((dest = malloc(sizeof(char) * my_strlen(path) + 10)) == NULL)
    return (NULL);
  while (path[j] != '\0' && path[j] != '.')
    {
      dest[j] = path[j];
      j++;
    }
  dest[j] = '\0';
  if (path[j] != '.')
    return (NULL);
  return (my_strcat(dest, ".cor"));
}

char		*get_file(char *path)
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
  return (my_strcat(dest, ".cor"));
}

int		make_header(char *file[2], t_header *header)
{
  if (!file || !header)
    return (84);
  if ((my_strncmp(file[0], NAME_STRING, 5)))
    return (84 + my_puterror("Missing name in the header!\n"));
  header->magic = MAGIC;
  if ((give_me_the_name(file[0], header)) == 84)
    return (84 + my_puterror("Incorrect name in the header!\n"));
  if ((my_strncmp(file[1], COMMENT_STRING, 8)))
    return (84 + my_puterror("Missing comment in the header!\n"));
  if ((give_me_comment(file[1], header)) == 84)
    return (84 + my_puterror("Incorrect comment in the header!\n"));
  return (0);
}
