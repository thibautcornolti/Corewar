/*
** vm.h for vm in /home/rectoria/delivery/Projets/CPE_2016_corewar/src/vm
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Mar 30 10:02:05 2017 Bastien
** Last update Sun Apr  2 12:39:25 2017 Thibaut Cornolti
*/

#ifndef INST_H_
# define INST_H_

int	live(t_inst *, t_ptr *, t_map *);
int	ld(t_inst *, t_ptr *, t_map *);
int	st(t_inst *, t_ptr *, t_map *);
int	add(t_inst *, t_ptr *, t_map *);
int	sub(t_inst *, t_ptr *, t_map *);
int	and(t_inst *, t_ptr *, t_map *);
int	or(t_inst *, t_ptr *, t_map *);
int	xor(t_inst *, t_ptr *, t_map *);
int	zjmp(t_inst *, t_ptr *, t_map *);
int	ldi(t_inst *, t_ptr *, t_map *);
int	sti(t_inst *, t_ptr *, t_map *);
int	ifork(t_inst *, t_ptr *, t_map *);
int	aff(t_inst *, t_ptr *, t_map *);

#endif	/* !INST_H_ */
