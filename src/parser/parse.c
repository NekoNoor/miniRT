/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:09:32 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/27 15:16:21 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"
#include "parser.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

/*
** u = unsigned int	(unsigned int, [0,>])
** r = ratio 		(double, [0,1])
** c = rgb color 	(unsigned int, per byte [0,255])
** x = xyz coords 	(3 doubles, [<,>])
** v = vector 		(3 doubles, [-1,1])
** f = fov 			(unsigned int, [0,180])
** d = double 		(double, [<,>])
*/

const t_table	g_ident_table[9] = {
	{"R", 2, "uu"},
	{"A", 2, "rc"},
	{"c", 3, "xvf"},
	{"l", 3, "xrc"},
	{"sp", 3, "xdc"},
	{"pl", 3, "xvc"},
	{"sq", 4, "xvdc"},
	{"cy", 5, "xvddc"},
	{"tr", 4, "xxxc"}
};

static int		get_num_fields(char *ident)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_ident_table) / sizeof(t_table))
	{
		if (ft_strcmp(ident, g_ident_table[i].ident))
			return (g_ident_table[i].num_fields);
		i++;
	}
	return (0);
}

static size_t	ft_strlen_space(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && !ft_isspace(s[len]))
		len++;
	return (len);
}

static int		clamp(int num, int min, int max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}

char			*get_identifier(char *s) // R,A,c,l,sp,pl,sq,cy,tr
{
	char	*ident;
	size_t	len;

	len = ft_strlen_space(s);
	ident = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ident, s, len + 1);
	return (ident);
}

/*
 *t_vec		get_vector(char *s)
 *{
 *}
 *
 *double		get_ratio(char *s) // 0.0-1.0
 *{
 *}
 */

int				get_fov(char *s) // 0-180
{
	int	fov;

	fov = ft_atoi(s);
	if (fov < 0 || fov > 180)
		puterror(__FILE__, __LINE__, "fov outside of [0-180]");
	return (clamp(fov, 0, 180));
}

int				get_color(char *s) // 0-255,0-255,0-255
{
	int	color;

	color = clamp(ft_atoi(s), 0, 255);
	while (ft_isdigit(*s))
		s++;
	color = color << 2 & clamp(ft_atoi(s), 0, 255);
	while (ft_isdigit(*s))
		s++;
	color = color << 2 & clamp(ft_atoi(s), 0, 255);
	return (color);
}

/*
 *double		get_double(char *s)
 *{
 *}
 */

t_field			*get_fields(char *line) // use above functions depending on identifier
{
	t_field	*fields;
	char	*ident;
	int		num_fields;

	ident = get_identifier(line);
	num_fields = get_num_fields(ident);
	if (num_fields == 0)
	{
		puterror(__FILE__, __LINE__, "invalid identifier");
		free(ident);
		return (NULL);
	}
	fields = malloc(sizeof(t_field) * (num_fields + 1));
	return (fields);
}

t_mlx_data		*parse_lines(t_list *lines)
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
