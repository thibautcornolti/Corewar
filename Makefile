##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Tue Mar 21 11:13:19 2017 Thibaut Cornolti
##

SRC	=	asm.c			\
		endian.c		\
		instruction_first.c	\
		instruction_mid.c	\
		instruction_mid_next.c	\
		instruction_last.c	\
		instruction_gen.c	\
		utils.c			\
		header.c		\
		parsing.c		\

OBJS	=	$(SRCS:.c=.o)

NAME	=	asm

CC	=	gcc -g

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-Llib/my

LIB	=	-lmy

all:	$(NAME)

$(NAME):
	cd lib/my/ && make
	$(CC) -o $(NAME) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -Wall -Wextra -pedantic

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
