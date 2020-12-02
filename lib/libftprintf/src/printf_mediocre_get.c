/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_get.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 16:39:12 by nschat        #+#    #+#                 */
/*   Updated: 2020/02/19 15:52:26 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

t_flags	get_flags(const char **format)
{
	t_flags		flags;

	flags = (t_flags){0, 0};
	while (**format)
	{
		if (**format == '-')
			flags.minus = 1;
		if (**format == '0')
			flags.zero = 1;
		if (**format != '-' && **format != '0')
			break ;
		(*format)++;
	}
	return (flags);
}

int		get_width(const char **format, va_list ap, t_data *data)
{
	int	field_width;

	field_width = -1;
	if (ft_isdigit(**format) || **format == '*')
	{
		if (**format == '*')
		{
			field_width = va_arg(ap, int);
			if (field_width < 0)
			{
				data->flags.minus = 1;
				data->flags.zero = 0;
				field_width *= -1;
			}
			(*format)++;
		}
		else
		{
			field_width = ft_atoi((char *)*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
	return (field_width);
}

int		get_precision(const char **format, va_list ap)
{
	int precision;

	precision = -1;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			precision = va_arg(ap, int);
			if (precision < 0)
				precision = -1;
			(*format)++;
		}
		else
		{
			precision = ft_atoi((char *)*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
	return (precision);
}

void	get_arg(const char **format, va_list ap, t_data *data)
{
	(*format)++;
	if (data->type == 'c')
		data->arg.c = va_arg(ap, int);
	if (data->type == 's')
		data->arg.s = va_arg(ap, char *);
	if (data->type == 'p')
		data->arg.p = va_arg(ap, void *);
	if (data->type == 'd' || data->type == 'i')
		data->arg.i = va_arg(ap, int);
	if (data->type == 'u' || data->type == 'x' || data->type == 'X')
		data->arg.ui = va_arg(ap, unsigned int);
	if (data->type == '%')
		data->arg.c = '%';
}
