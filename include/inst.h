/*
** inst.h for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Mar 21 11:13:51 2017 Thibaut Cornolti
** Last update Tue Mar 21 11:30:04 2017 Thibaut Cornolti
*/

#ifndef INST_H_
# define INST_H_

int	inst_live(t_arg *, int);
int	inst_ld(t_arg *, t_arg *, int);
int	inst_st(t_arg *, t_arg *, int);
int	inst_add(t_arg *, t_arg *, t_arg *, int);
int	inst_sub(t_arg *, t_arg *, t_arg *, int);
int	inst_and(t_arg *, t_arg *, t_arg *, int);
int	inst_or(t_arg *, t_arg *, t_arg *, int);
int	inst_xor(t_arg *, t_arg *, t_arg *, int);
int	inst_zjmp(t_arg *, int);
int	inst_ldi(t_arg *, t_arg *, t_arg *, int);
int	inst_sti(t_arg *, t_arg *, t_arg *, int);
int	inst_fork(t_arg *, int);
int	inst_lld(t_arg *, t_arg *, int);
int	inst_lldi(t_arg *, t_arg *, t_arg *, int);
int	inst_lfork(t_arg *, int);
int	inst_aff(t_arg *, int);

#endif /* !INST_H_ */
