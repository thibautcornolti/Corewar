##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Thu Mar 30 12:40:17 2017 Luc
##

SRC	=	parsing.c			\

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
