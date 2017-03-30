/*
** map.h for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm/include
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 11:07:58 2017 Luc
** Last update Thu Mar 30 18:26:52 2017 Thibaut Cornolti
*/

typedef struct s_champ	t_champ;

typedef struct		s_cmd
{
  int			prog_number;
  int			load_adress;
  char			*prog_name;
  struct s_cmd		*next;
}			t_cmd;

int	get_info_champ(char **, int *, int *, int *);
int	get_champion(t_cmd **, char **);
