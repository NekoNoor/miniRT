# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/25 03:39:52 by nschat        #+#    #+#                  #
#    Updated: 2020/12/02 17:25:50 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
	PLATFORM = linux
endif
ifeq ($(UNAME), Darwin)
	PLATFORM = macos
endif

CC = gcc
INCLUDES = -I include -I lib/libmlx-$(PLATFORM) -I lib/libftprintf/include -I lib/libgnl -I lib/libft/include
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L lib/libmlx-$(PLATFORM) -L lib/libftprintf -L lib/libgnl -L lib/libft -lmlx -lftprintf -lgnl -lft
ifeq ($(UNAME), Linux)
	LDFLAGS += -lXext -lX11 -lm -lz
else
	LDFLAGS += -framework OpenGL -framework AppKit
endif

HDR = parser.h \
	  renderer.h
SRC = renderer/render.c \
	  parser/parse.c \
	  parser/file.c \
	  error/puterror.c \
	  main.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

LDIR = lib
LIBS = $(LDIR)/libftprintf/libftprintf.a \
	   $(LDIR)/libgnl/libgnl.a \
	   $(LDIR)/libft/libft.a
ifeq ($(UNAME), Linux)
	LIBS += $(LDIR)/libmlx-$(PLATFORM)/libmlx.a
else
	LIBS += $(LDIR)/libmlx-$(PLATFORM)/libmlx.dylib
endif

NAME = miniRT

vpath %.c src
vpath %.h include

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: %.c $(HDR)
	@mkdir -p $(ODIR)
	@mkdir -p $(ODIR)/parser
	@mkdir -p $(ODIR)/renderer
	@mkdir -p $(ODIR)/error
	$(CC) $(CFLAGS) -c $< -o $@

$(LDIR)/libmlx-$(PLATFORM)/libmlx.a:
	$(MAKE) -C $(dir $@)

$(LDIR)/libmlx-$(PLATFORM)/libmlx.dylib:
	$(MAKE) -C $(dir $@)
	cp $@ .

$(LDIR)/libftprintf/libftprintf.a:
	$(MAKE) -C $(dir $@)

$(LDIR)/libgnl/libgnl.a:
	$(MAKE) -C $(dir $@)

$(LDIR)/libft/libft.a:
	$(MAKE) -C $(dir $@)

clean:
	$(MAKE) -C lib/libmlx-$(PLATFORM) clean
	$(MAKE) -C lib/libgnl clean
	$(MAKE) -C lib/libft clean
	$(RM) -r $(ODIR)

fclean: clean
	$(RM) libmlx.dylib
	$(RM) $(LIBS)
	$(RM) $(NAME)

re: fclean all
