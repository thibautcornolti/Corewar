/*
** info.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Mon Mar 20 13:22:56 2017 Thibaut Cornolti
** Last update Sun Mar 26 15:19:12 2017 Luc
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

void		add_octet_to_list(t_label *vache_qui_rit, int i)
{
  while (vache_qui_rit != NULL)
    {
      l_pos += i;
      vache_qui_rit = vache_qui_rit->next;
    }
}
