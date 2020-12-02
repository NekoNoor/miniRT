/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_print.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:58:16 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:06:42 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"
#include <unistd.h>

static int			print_char(t_data *data)
{
	int	padding;
	int	len;

	padding = 0;
	len = 1;
	if (data->flags.minus == 0 && len < data->width)
		padding += pad(data->fd, ' ', data->width - len);
	write(data->fd, &data->arg.c, len);
	if (data->flags.minus == 1 && len < data->width)
		padding += pad(data->fd, ' ', data->width - len);
	return (len + padding);
}

static int			print_string(t_data *data)
{
	int	padding;
	int	len;

	padding = 0;
	if (data->arg.s == NULL)
		data->arg.s = "(null)";
	len = ft_strlen(data->arg.s);
	if (data->precision != -1 && len > data->precision)
		len = data->precision;
	if (data->flags.minus == 0 && len < data->width)
		padding += pad(data->fd, ' ', data->width - len);
	write(data->fd, data->arg.s, len);
	if (data->flags.minus == 1 && len < data->width)
		padding += pad(data->fd, ' ', data->width - len);
	return (len + padding);
}

const t_dispatch	g_dispatch_table[10] = {
		{'c', &print_char},
		{'s', &print_string},
		{'p', &print_number},
		{'d', &print_number},
		{'i', &print_number},
		{'u', &print_number},
		{'x', &print_number},
		{'X', &print_number},
		{'%', &print_char},
		{'t', &print_string}
};

static int			select_func(t_data *data)
{
	size_t				i;

	i = 0;
	while (i < sizeof(g_dispatch_table) / sizeof(t_dispatch))
	{
		if (data->type == g_dispatch_table[i].type)
			return ((*g_dispatch_table[i].print)(data));
		i++;
	}
	return (0);
}

int			print_list(t_pflist *list)
{
	int					len;

	len = 0;
	while (list)
	{
		len += select_func(list->data);
		list = list->next;
	}
	return (len);
}
