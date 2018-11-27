# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:06:41 by lutsiara          #+#    #+#              #
#    Updated: 2018/11/27 13:23:09 by flcarre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCDIR = ./

INCDIR = ./

LIBDIR = ./

LIB = libft.a

LIBSRCS = $(SRCDIR)ft_atoi.c \
		  $(SRCDIR)ft_bzero.c \
		  $(SRCDIR)ft_countword.c \
		  $(SRCDIR)ft_delcontent.c \
		  $(SRCDIR)ft_digitlen.c \
		  $(SRCDIR)ft_isalnum.c \
		  $(SRCDIR)ft_isalpha.c \
		  $(SRCDIR)ft_isascii.c \
		  $(SRCDIR)ft_isdigit.c \
		  $(SRCDIR)ft_islower.c \
		  $(SRCDIR)ft_isprint.c \
		  $(SRCDIR)ft_isspace.c \
		  $(SRCDIR)ft_isupper.c \
		  $(SRCDIR)ft_iswhitespace.c \
		  $(SRCDIR)ft_itoa.c \
		  $(SRCDIR)ft_lstadd.c \
		  $(SRCDIR)ft_lstdel.c \
		  $(SRCDIR)ft_lstdelone.c \
		  $(SRCDIR)ft_lstdup.c \
		  $(SRCDIR)ft_lstdupone.c \
		  $(SRCDIR)ft_lstenqueue.c \
		  $(SRCDIR)ft_lstiter.c \
		  $(SRCDIR)ft_lstmap.c \
		  $(SRCDIR)ft_lstnew.c \
		  $(SRCDIR)ft_memalloc.c \
		  $(SRCDIR)ft_memccpy.c \
		  $(SRCDIR)ft_memchr.c \
		  $(SRCDIR)ft_memcmp.c \
		  $(SRCDIR)ft_memcpy.c \
		  $(SRCDIR)ft_memdel.c \
		  $(SRCDIR)ft_memmove.c \
		  $(SRCDIR)ft_memset.c \
		  $(SRCDIR)ft_putchar.c \
		  $(SRCDIR)ft_putchar_fd.c \
		  $(SRCDIR)ft_putendl.c \
		  $(SRCDIR)ft_putendl_fd.c \
		  $(SRCDIR)ft_putnbr.c \
		  $(SRCDIR)ft_putnbr_fd.c \
		  $(SRCDIR)ft_putstr.c \
		  $(SRCDIR)ft_putstr_fd.c \
		  $(SRCDIR)ft_strcat.c \
		  $(SRCDIR)ft_strchr.c \
		  $(SRCDIR)ft_strclr.c \
		  $(SRCDIR)ft_strcmp.c \
		  $(SRCDIR)ft_strcpy.c \
		  $(SRCDIR)ft_strdel.c \
		  $(SRCDIR)ft_strdup.c \
		  $(SRCDIR)ft_strequ.c \
		  $(SRCDIR)ft_striter.c \
		  $(SRCDIR)ft_striteri.c \
		  $(SRCDIR)ft_strjoin.c \
		  $(SRCDIR)ft_strlcat.c \
		  $(SRCDIR)ft_strlen.c \
		  $(SRCDIR)ft_strmap.c \
		  $(SRCDIR)ft_strmapi.c \
		  $(SRCDIR)ft_strncat.c \
		  $(SRCDIR)ft_strncmp.c \
		  $(SRCDIR)ft_strncpy.c \
		  $(SRCDIR)ft_strnequ.c \
		  $(SRCDIR)ft_strnew.c \
		  $(SRCDIR)ft_strnstr.c \
		  $(SRCDIR)ft_strrchr.c \
		  $(SRCDIR)ft_strsplit.c \
		  $(SRCDIR)ft_strstr.c \
		  $(SRCDIR)ft_strsub.c \
		  $(SRCDIR)ft_strtabdel.c \
		  $(SRCDIR)ft_strtabnew.c \
		  $(SRCDIR)ft_strtrim.c \
		  $(SRCDIR)ft_tolower.c \
		  $(SRCDIR)ft_toupper.c \
		  $(SRCDIR)ft_abs.c \
		  $(SRCDIR)ft_paw.c \
		  $(SRCDIR)ft_lstipos.c \
		  $(SRCDIR)get_next_line.c

LIBOBJS = $(LIBSRCS:.c=.o)

SRCS = $(SRCDIR)main.c \
	   $(SRCDIR)ft_new_tetrimino.c \
		 $(SRCDIR)ft_strtobin.c \
		 $(SRCDIR)ft_get_tetriminos.c \
		 $(SRCDIR)ft_del_tetriminos.c \
		 $(SRCDIR)ft_set_mask.c \
		 $(SRCDIR)ft_set_mask2.c \
		 $(SRCDIR)ft_isinvalid.c \
	   $(SRCDIR)ft_solve.c \
	   $(SRCDIR)ft_measure_tetrimino.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIB) $(OBJS)
	@$(CC) -o $@ $(OBJS) -I $(INCDIR) $(FLAGS) -L $(LIBDIR) -lft
	@echo "make $(NAME)\033[0;32m ✓\033[0m"

$(LIB): $(LIBOBJS)
	@ar rc $(LIB) $(LIBOBJS)
	@ranlib $(LIB)
	@echo "make $(LIB)\033[0;32m ✓\033[0m"

all: $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< -I $(INCDIR) $(FLAGS)

clean:
	@/bin/rm -rf $(OBJS) $(LIBOBJS)
	@echo "rm *.o\033[0;32m ✓\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME) $(LIB)
	@echo "rm $(NAME) $(LIB)\033[0;32m ✓\033[0m"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
