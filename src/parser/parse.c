/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:09:32 by nschat        #+#    #+#                 */
/*   Updated: 2020/07/11 16:35:52 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "libft.h"
#include <stdlib.h>

t_mlx_data	*parse_lines(t_list *lines)
{
	t_mlx_data	*data;
	size_t		i;

	data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	i = 0;
	if (((char *)lines->content)[i] == 'R')
	{
		i++;
		while (ft_isspace(((char *)lines->content)[i]))
			i++;
		data->width = ft_atoi(lines->content + i);
		while (ft_isdigit(((char *)lines->content)[i]))
			i++;
		data->height = ft_atoi(lines->content + i);
	}
	else
	{
		data->width = -1;
		data->height = -1;
	}
	return (data);
}
