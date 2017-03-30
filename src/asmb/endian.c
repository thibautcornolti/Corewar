/*
** endian.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 14:44:55 2017 Thibaut Cornolti
** Last update Wed Mar  8 14:50:29 2017 Thibaut Cornolti
*/

#include <unistd.h>
#include "asm.h"

static char	*my_revnstr(char *str, int length)
{
  int		count;
  char		temp;

  count = length;
  if (length > 1)
    {
      count = 0;
      while (count < length / 2)
	{
	  temp = str[count];
	  str[count] = str[length - count - 1];
	  str[length - count - 1] = temp;
	  count += 1;
	}
    }
  return (str);
}

void		write_endian(int fd, void *ptr, int size)
{
  char		*sptr;

  sptr = ptr;
  my_revnstr(sptr, size);
  write(fd, sptr, size);
}
