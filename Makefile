# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/25 03:39:52 by nschat        #+#    #+#                  #
#    Updated: 2020/06/27 14:16:06 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
INCLUDES = -I include -I lib/libmlx -I lib/libgnl -I lib/libft/include
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L lib/libmlx -L lib/libgnl -L lib/libft -lmlx -lgnl -lft -framework OpenGL -framework AppKit

HDR = utils.h \
	  parser.h \
	  renderer.h
SRC = renderer/render.c \
	  parser/parse.c \
	  parser/file.c \
	  utils/color.c \
	  main.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LDIR = lib
LIBS = $(LDIR)/libmlx/libmlx.dylib \
	   $(LDIR)/libgnl/libgnl.a \
	   $(LDIR)/libft/libft.a

NAME = miniRT

vpath %.c src
vpath %.h include

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBS) libmlx.dylib
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: %.c $(HDR)
	@mkdir -p $(ODIR)
	@mkdir -p $(ODIR)/utils
	@mkdir -p $(ODIR)/parser
	@mkdir -p $(ODIR)/renderer
	$(CC) $(CFLAGS) -c $< -o $@

libmlx.dylib: $(LDIR)/libmlx/libmlx.dylib
	cp $(LDIR)/libmlx/libmlx.dylib $@

$(LDIR)/libmlx/libmlx.dylib:
	$(MAKE) -C $(dir $@)

$(LDIR)/libgnl/libgnl.a:
	$(MAKE) -C $(dir $@)

$(LDIR)/libft/libft.a:
	$(MAKE) -C $(dir $@)

clean:
	$(MAKE) -C lib/libmlx clean
	$(MAKE) -C lib/libgnl clean
	$(MAKE) -C lib/libft clean
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) $(LIBS)
	$(RM) $(NAME)
	$(RM) libmlx.dylib

re: fclean all
