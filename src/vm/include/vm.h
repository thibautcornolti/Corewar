/*
** vm.h for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:02:05 2017 Bastien
** Last update Sat Apr  1 21:49:30 2017 Thibaut Cornolti
*/

#ifndef VM_H_
# define VM_H_

# define MAGIC                  0xea83f3
# define MEM_SIZE		(6*1024)
# define IDX_MOD		521
# define MAX_ARGS_NUMBER	4

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		1

# define REG_NUMBER		16
# define DIR_SIZE		4
# define REG_SIZE		DIR_SIZE
# define NAME_LENGTH            128
# define COMMENT_LENGTH         2048

# define T_REG			1
# define T_DIR			2
# define T_IND			4

# define PTR_INDEX		ptr->index_map % MEM_SIZE

typedef struct s_champ	t_champ;

typedef struct		s_ptr
{
  t_champ		*father;
  char			carry;
  int			cycle;
  int			index_map;
  struct s_ptr		*next;
}			t_ptr;

typedef struct		s_champ
{
  char			*name;
  char			*comment;
  int			color;
  t_ptr			*chained_ptr;
  int			live;
  int			reg[REG_SIZE];
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct		s_arg
{
  char			type;
  int			arg;
}			t_arg;

typedef struct		s_inst
{
  char			inst;
  t_arg			arg[3];
}			t_inst;

typedef struct		s_map
{
  char			arena[MEM_SIZE];
  char			color[MEM_SIZE];
}			t_map;

typedef struct          s_cmd
{
  int                   prog_number;
  int                   load_adress;
  char                  *prog_name;
  struct s_cmd          *next;
}			t_cmd;		

typedef struct		s_header
{
  int			magic;
  char			prog_name[NAME_LENGTH + 1];
  int			prog_size;
  char			comment[COMMENT_LENGTH + 1];
}			t_header;

int			binary_to_type(char);
int			type_to_size(char, char);
int			inst_to_time(char);
void			*endian(void *, int);
void			my_memncpy(void *, void *, int);
int		        get_nbr_live(t_champ *);
int			pars_cmd(t_cmd **, char **);
t_champ			*load_champ(t_champ *, t_map *, t_cmd *);
int			translate(t_ptr *, t_map *);
void			fill_arg_live(t_inst *, t_map *, t_ptr *);
void			fill_arg_spec(t_inst *, t_map *, t_ptr *);
void			redirect_inst(t_inst *, t_map *, t_ptr *);
t_champ			*get_last_live(t_champ *);
int			get_arg_value(t_arg *, t_ptr *, t_map *);

#endif	/* !VM_H_ */
