##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Thu Mar 30 21:21:27 2017 Thibaut Cornolti
##

SRC	=	parsing.c			\
		alive.c				\
		charge_champ.c			\
		endian.c			\
		google_translate.c		\
		utils_translate.c		\
		vm.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	corewar

CC	=	gcc -g

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-L../lib/my

LIB	=	-lmy

all:	$(NAME)

$(NAME):
	cd ../lib/my/ && make
	$(CC) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -o $(NAME) -Wall -Wextra -pedantic

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
