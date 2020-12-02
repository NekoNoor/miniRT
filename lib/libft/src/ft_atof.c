/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 17:32:43 by nschat        #+#    #+#                 */
/*   Updated: 2020/12/02 17:49:37 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double result;
	double div;

	result = (double)ft_atoi(str);
	while(ft_isdigit(*str))
		str++;
	if (*str == '.')
		str++;
	div = 10.0;
	while(ft_isdigit(*str))
	{
		result += (double)(*str - '0') / div;
		div *= 10.0;
		str++;
	}
	return (result);
}
