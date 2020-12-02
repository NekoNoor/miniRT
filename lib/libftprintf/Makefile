# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 17:30:18 by nschat        #+#    #+#                  #
#    Updated: 2020/10/19 15:35:02 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar rcs
IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

HDR = $(IDIR)/printf_mediocre.h
SRC = printf_mediocre.c \
	  printf_mediocre_analyze.c \
	  printf_mediocre_get.c \
	  printf_mediocre_list.c \
	  printf_mediocre_nbr.c \
	  printf_mediocre_print.c \
	  printf_mediocre_str.c \
	  printf_mediocre_utils.c
TEST_SRC = test.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))
TEST_OBJ = $(addprefix $(ODIR)/,$(TEST_SRC:.c=.o))

NAME = libftprintf.a
TEST_NAME = test

vpath %.c src

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

$(ODIR)/%.o: %.c $(HDR)
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_NAME): $(NAME) | $(TEST_OBJ)
	$(CC) $(CFLAGS) -L . -lftprintf $| -o $@

run_test: $(TEST_NAME)
	./$<

clean:
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re: fclean all
