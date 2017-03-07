/*
** asm.h for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:25:17 2017 Thibaut Cornolti
** Last update Tue Mar  7 14:39:15 2017 Thibaut Cornolti
*/

#ifndef ASM_H_
# define ASM_H_

typedef struct	s_bytecode
{
  char		instruction;
  int		arg1;
  int		arg2;
}		t_bytecode;

#endif /* !ASM_H_ */
