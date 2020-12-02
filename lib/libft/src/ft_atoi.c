/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:21 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/12 06:55:17 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static unsigned char	ft_getvalue(char c, int base)
{
	if (base <= 10 && c >= '0' && c <= base - 1 + '0')
		return (c - '0');
	if (base > 10 && ft_isdigit(c))
		return (c - '0');
	if (base > 10 && c >= 'A' && c <= base - 10 - 1 + 'A')
		return (c - 'A' + 10);
	if (base > 10 && c >= 'a' && c <= base - 10 - 1 + 'a')
		return (c - 'a' + 10);
	return (255);
}

long					ft_strtol(const char *str, int base)
{
	int				sign;
	unsigned long	nbr;
	unsigned long	max;
	int				lim;

	if (base < 2 || base > 36)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (base == 10 && *str == '-') ? -1 : 1;
	if (base == 10 && (*str == '+' || *str == '-'))
		str++;
	nbr = 0;
	max = (sign == -1) ? (unsigned long)LONG_MAX + 1 : LONG_MAX;
	lim = (sign == -1) ? 8 : 7;
	max /= base;
	while (ft_getvalue(*str, base) != 255)
	{
		if (nbr > max || (nbr == max && ft_getvalue(*str, base) > lim))
			return ((sign == -1) ? LONG_MIN : LONG_MAX);
		nbr = nbr * base + ft_getvalue(*str, base);
		str++;
	}
	return ((long)(nbr * sign));
}

int						ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, 10));
}
