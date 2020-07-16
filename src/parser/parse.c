/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:09:32 by nschat        #+#    #+#                 */
/*   Updated: 2020/07/16 18:33:07 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "libft.h"
#include <stdlib.h>

/*
 *char		*get_identifier(char *s) // R,A,c,l,sp,pl,cy,tr
 *{
 *}
 *
 *t_vec		get_vector(char *s)
 *{
 *}
 *
 *double		get_ratio(char *s) // 0.0-1.0
 *{
 *}
 *
 *int			get_fov(char *s) // 0-180
 *{
 *}
 *
 *int			get_color(char *s) // 0-255,0-255,0-255
 *{
 *}
 *
 *double		get_double(char *s)
 *{
 *}
 *
 *char		**get_fields(char *line) // use above functions depending on identifier
 *{
 *}
 */

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
