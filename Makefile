# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/25 03:39:52 by nschat        #+#    #+#                  #
#    Updated: 2020/05/31 21:25:55 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = clang
IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR) -I mlx

HDR = $(IDIR)/minirt.h
SRC = main.c \
	  file.c \
	  parse.c

ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = miniRT

CRED = \x1b[31m
CGREEN = \x1b[32m
CYELLOW = \x1b[33m
CBLUE = \x1b[34m
CCYAN = \x1b[36m
CDEFAULT = \x1b[39m
CDEF = $(CDEFAULT)

CMINUS = $(CRED)[-]$(CDEF)
CPLUS = $(CGREEN)[+]$(CDEF)
CNORM = $(CYELLOW)[~]$(CDEF)

TIME = $(CCYAN)[$$(date +"%H:%M:%S")]$(CDEF)

vpath %.c src

.PHONY: clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(TIME) $(CPLUS) $(CGREEN)Linking objects into $@...$(CDEF)"
	@$(CC) $(CFLAGS) -Lmlx -lmlx -c $^ -o $@

$(ODIR)/%.o: %.c $(HDR)
	@echo "$(TIME) $(CPLUS) $(CBLUE)Compiling $< to $@...$(CDEF)"
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning object directory...$(CDEF)"
	@$(RM) -r $(ODIR)

fclean: clean
	@echo "$(TIME) $(CMINUS) $(CRED)Cleaning $(NAME)...$(CDEF)"
	@$(RM) $(NAME)

re: fclean all
