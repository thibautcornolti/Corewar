/*
** info.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Mar 20 13:22:56 2017 Thibaut Cornolti
** Last update Mon Mar 20 13:23:43 2017 Thibaut Cornolti
*/

int		take_info(char *path)
{
  char		c;
  int		fd;
  int		line;

  if ((fd = open(path, O_RDONLY)) == -1)
    exit(84);
  while ((read(fd, &c, 1)) > 0)
    {
      if (c == '\n')
	line += 1;
    }
  close(fd);
  return (line);
}
