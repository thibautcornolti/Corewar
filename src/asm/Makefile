##
## Makefile for Makefile in /home/thibrex/delivery/CPool_Day10/do-op
## 
## Made by Thibaut Cornolti
## Login   <thibaut.cornolti@epitech.eu>
## 
## Started on  Sat Oct 15 22:12:03 2016 Thibaut Cornolti
## Last update Thu Mar 30 09:33:34 2017 Thibaut Cornolti
##

SRC	=	asm.c			\
		endian.c		\
		instruction.c		\
		utils.c			\
		header.c		\
		parsing.c		\
		size.c			\
		parsing_reading_info.c	\
		label.c			\
		verify_type_arg.c	\
		writer.c		\

OBJS	=	$(SRCS:.c=.o)

NAME	=	asm

CC	=	gcc -g

HEADER	=	include/

RM	=	rm -f

LIB_P	=	-L../lib/my

LIB	=	-lmy

all:	$(NAME)

$(NAME):
	cd ../lib/my/ && make
	$(CC) -o $(NAME) -I$(HEADER) $(SRC) $(LIB_P) $(LIB) -Wall -Wextra -pedantic

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
