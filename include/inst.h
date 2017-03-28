/*
** inst.h for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Mar 21 11:13:51 2017 Thibaut Cornolti
** Last update Tue Mar 28 11:12:38 2017 Luc
*/

#ifndef INST_H_
# define INST_H_

int	inst_gen(char, t_arg[], int, int);
int	inst_live(char, t_arg[], int);
int	inst_ind(char, t_arg[], int);

#endif /* !INST_H_ */
