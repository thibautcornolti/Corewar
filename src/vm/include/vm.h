/*
** vm.h for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:02:05 2017 Bastien
** Last update Thu Mar 30 21:19:29 2017 Bastien
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

typedef struct	s_ptr
{
  t_champ	*father;
  char		carry;
  int		live;
  int		cycle;
  int		index_map;
  struct s_ptr	*next;
}		t_ptr;

typedef struct		s_champ
{
  char			*name;
  char			*comment;
  t_ptr			*chained_ptr;
  int			reg[REG_SIZE];
  static s_champ	*next;
}			t_champ;

typedef struct	s_arg
{
  char		type;
  int		arg;
}		t_arg;

typedef struct	s_inst
{
  char		inst;
  t_arg		arg[3];
}		t_inst;

typedef struct	s_map
{
  char	arena[MEM_SIZE + 1];
  char	color[MEM_SIZE + 1];
}		t_map;

typedef struct          s_cmd
{
  int                   prog_number;
  int                   load_adress;
  char                  *prog_name;
  struct s_cmd          *next;
}			t_cmd;		

typedef struct	s_header
{
  int           magic;
  char          prog_name[NAME_LENGTH + 1];
  int           prog_size;
  char          comment[COMMENT_LENGTH + 1];
}		t_header;

int		binary_to_type(char);
int		type_to_size(char, char);
void		*endian(void *, int);
void		my_memncpy(void *, void *, int);

#endif	/* !VM_H_ */
