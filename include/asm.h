/*
** asm.h for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:25:17 2017 Thibaut Cornolti
** Last update Wed Mar  8 15:09:03 2017 Luc
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

typedef struct	s_bytecode
{
  char		instruction;
  int		arg1;
  int		arg2;
}		t_bytecode;

typedef struct	s_champion
{
  char		**champion;
}		t_champion;

int		make_header(t_champion *champ);

#endif /* !ASM_H_ */
