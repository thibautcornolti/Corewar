/*
** map.h for emacs in /home/sankamille/delivery/CPE_2016_corewar/src/vm/include
** 
** Made by Luc
** Login   <luc.brulet@epitech.eu>
** 
** Started on  Thu Mar 30 11:07:58 2017 Luc
** Last update Thu Mar 30 16:24:11 2017 Luc
*/

typedef struct		s_arg
{
  int			prog_number;
  int			load_adress;
  char			*prog_name;
  struct s_champion	*next;
}			t_arg;

int	add_to_list(t_champ **, int, int, char *);
int	get_info_champ(char **, int *, int *, int *);
int	get_champion(t_champ **, char **);
