##
## Makefile for Makefile in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Thu Mar 30 09:28:59 2017 Thibaut Cornolti
## Last update Sun Apr  2 23:09:15 2017 Thibaut Cornolti
##

ASM_SRC	=	asm/

VM_SRC	=	corewar/


all:	as vm

as:
	cd $(ASM_SRC) && make

vm:
	cd $(VM_SRC) && make

clean:
	cd $(ASM_SRC) && make clean
	cd $(VM_SRC) && make clean

fclean:
	cd $(ASM_SRC) && make fclean
	cd $(VM_SRC) && make fclean

re:
	cd $(ASM_SRC) && make re
	cd $(VM_SRC) && make re
