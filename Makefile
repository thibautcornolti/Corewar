##
## Makefile for Makefile in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Thu Mar 30 09:28:59 2017 Thibaut Cornolti
## Last update Thu Mar 30 09:34:43 2017 Thibaut Cornolti
##

ASM_SRC	=	src/asm/

VM_SRC	=	src/vm/

all:	asm vm

asm:
	cd $(ASM_SRC) && make
	mv $(ASM_SRC)/asm .

vm:
	cd $(VM_SRC) && make
	mv $(VM_SRC)/corewar .

clean:
	cd $(ASM_SRC) && make clean
	cd $(VM_SRC) && make clean

fclean:
	cd $(ASM_SRC) && make fclean
	cd $(VM_SRC) && make fclean

re:
	cd $(ASM_SRC) && make re
	mv $(ASM_SRC)/asm .
	cd $(VM_SRC) && make re
	mv $(VM_SRC)/corewar .
