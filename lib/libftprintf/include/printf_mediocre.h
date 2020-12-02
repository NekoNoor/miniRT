/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:17:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:07:52 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_MEDIOCRE_H
# define PRINTF_MEDIOCRE_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int minus;
	int zero;
}				t_flags;

typedef union	u_arg
{
	char			c;
	char			*s;
	int				i;
	unsigned int	ui;
	unsigned long	ul;
	void			*p;
}				t_arg;

typedef struct	s_data
{
	int		fd;
	t_flags	flags;
	int		width;
	int		precision;
	char	type;
	t_arg	arg;
}				t_data;

typedef struct	s_pflist
{
	t_data			*data;
	struct s_pflist	*next;
}				t_pflist;

typedef struct	s_dispatch
{
	char	type;
	int		(*print)(t_data *);
}				t_dispatch;

int				ft_vdprintf(int fd, const char *format, va_list ap);
int				ft_vprintf(const char *format, va_list ap);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);

t_pflist		*analyze_format(int fd, const char *format, va_list ap);

t_flags			get_flags(const char **format);
int				get_width(const char **format, va_list ap, t_data *data);
int				get_precision(const char **format, va_list ap);
void			get_arg(const char **format, va_list ap, t_data *data);

t_pflist		*ft_pflstnew(t_data *data);
t_pflist		*ft_pflstlast(t_pflist *lst);
void			ft_pflstadd_back(t_pflist **alst, t_pflist *new);
void			free_list(t_pflist **alst);

int				pad(int fd, char c, size_t len);

int				print_number(t_data *data);

int				print_list(t_pflist *list);

size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			ft_putnbr(int fd, unsigned long nbr, unsigned long base, int offs);

#endif
