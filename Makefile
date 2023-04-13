# E89 Pedagogical & Technical Lab
# project:     rev
# created on:  2022-11-28 - 11:34 +0100
# 1st author:  victor.vandeputte - victor.vandeputte
# description: Makefile

NAME	=	rev

SRCS	=	src/test_rev.c	\
		src/reverse.c	\
		src/strlen.c	\
		src/strcat.c 	\
		src/strcpy.c	\
		src/malloc.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

save:
	git status
	git add Makefile src/*.c include/*.h
	git commit -m "$(NAME) sauvegarde"
	git push

exe:
	make
	./surface
	make fclean

mclean:
	rm src/*.c~ src/*.o include/*.h~

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re
