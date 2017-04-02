##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Sun Apr  2 12:07:34 2017 Bastien
##

SRC	=	parsing.c			\
		alive.c				\
		charge_champ.c			\
		endian.c			\
		google_translate.c		\
		bing_translate.c		\
		utils_translate.c		\
		vm.c				\
		utils.c				\
		instruction_1.c			\
		instruction_2.c			\
		instruction_3.c			\
		instruction_4.c			\

OBJS	=	$(SRCS:.c=.o)

NAME	=	corewar

CC	=	gcc

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
