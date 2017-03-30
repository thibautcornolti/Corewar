/*
** endian.c for vm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar/src/vm
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Thu Mar 30 17:30:12 2017 Thibaut Cornolti
** Last update Thu Mar 30 17:31:10 2017 Thibaut Cornolti
*/

void		*endian(void *ptr, int length)
{
  int		count;
  char		temp;
  char		*str;

  str = ptr;
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
  return (ptr);
}
