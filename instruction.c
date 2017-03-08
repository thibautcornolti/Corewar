/*
** instruction.c for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Wed Mar  8 14:53:48 2017 Thibaut Cornolti
** Last update Wed Mar  8 15:17:27 2017 Thibaut Cornolti
*/

int		inst_live(int player_number, int fd)
{
  char		inst;

  inst = 1;
  write(fd, &inst, 1);
}
