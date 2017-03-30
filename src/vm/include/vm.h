/*
** vm.h for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:02:05 2017 Bastien
** Last update Thu Mar 30 16:45:32 2017 Thibaut Cornolti
*/

#ifndef VM_H_
# define VM_H_

# define MAGIC                  0xea83f3
# define MEM_SIZE		(6*1024)
# define IDX_MOD		521
# define MAX_ARGS_NUMBER	4

# define REG_NUMBER		16
# define DIR_SIZE		4
# define REG_SIZE		DIR_SIZE
# define NAME_LENGTH            128
# define COMMENT_LENGTH         2048

typedef struct	s_lchamp
{
  char	*name;
  char	*comment;
}		t_lchamp;

typedef struct	s_inst
{
  char		inst;
  t_arg		arg[3];
}		t_inst;

typedef struct	s_arg
{
  char		type;
  int		arg;
}		t_arg;

typedef struct	s_header
{
  int           magic;
  char          prog_name[NAME_LENGTH + 1];
  int           prog_size;
  char          comment[COMMENT_LENGTH + 1];
}		t_header;

#endif	/* !VM_H_ */
