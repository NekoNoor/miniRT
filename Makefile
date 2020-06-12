# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/25 03:39:52 by nschat        #+#    #+#                  #
#    Updated: 2020/06/12 16:10:35 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
INCLUDES = -I include -I lib/libmlx -I lib/libgnl
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

HDR = include/minirt.h
SRC = main.c \
	  parser/file.c \
	  parser/parse.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LDIR = lib
LIBS = lib/libmlx/libmlx.dylib \
	   lib/libgnl/libgnl.a

NAME = miniRT

vpath %.c src

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) -c $^ -o $@

$(ODIR)/%.o: %.c $(HDR)
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LDIR)/libmlx/libmlx.dylib:
	$(MAKE) -C lib/libmlx

$(LDIR)/libgnl/libgnl.a:
	$(MAKE) -C lib/libgnl

clean:
	$(MAKE) -C lib/libgnl clean
	$(MAKE) -C lib/libmlx clean
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(LIBS)
	$(RM) $(NAME)

re: fclean all
