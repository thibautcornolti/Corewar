/*
** asm.h for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:25:17 2017 Thibaut Cornolti
** Last update Wed Mar  8 17:54:07 2017 Thibaut Cornolti
*/

#ifndef ASM_H_
# define ASM_H_

# define MAGIC			0xea83f3
# define NAME_LENGTH		128
# define COMMENT_LENGTH		2048
# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		'abcdefghijklmnopqrstuvwxyz_0123456789'
# define NAME_STRING		".name"
# define COMMENT_STRING		".comment"
# define REG_NUMBER		16

# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

typedef struct	s_arg
{
  char		type;
  int		arg;
}		t_arg;

typedef struct	s_bytecode
{
  char		instruction;
  int		arg1;
  int		arg2;
}		t_bytecode;

void		write_endian(int, void *, int);
void		inst_live(int, int);
void		inst_ld(t_arg *, t_arg *, int);

#endif /* !ASM_H_ */
