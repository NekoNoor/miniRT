/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 17:10:08 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:07:25 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"
#include <unistd.h>

int		ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(const char *str)
{
	unsigned	out;
	int			sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+');
	out = 0;
	while (ft_isdigit(*str))
	{
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * sign);
}

void	ft_putnbr(int fd, unsigned long nbr, unsigned long base, int offs)
{
	const char	*chars = "0123456789ABCDEF0123456789abcdef";

	if (nbr >= base)
		ft_putnbr(fd, nbr / base, base, offs);
	write(fd, chars + (nbr % base) + offs, 1);
}

int		pad(int fd, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(fd, &c, 1);
		i++;
	}
	return (len);
}
