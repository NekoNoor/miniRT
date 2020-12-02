/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:09:32 by nschat        #+#    #+#                 */
/*   Updated: 2020/12/02 17:26:48 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "renderer.h"
#include "parser.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

/*
** i = int			(int, [0,>])
** r = ratio 		(double, [0,1])
** c = rgb color 	(int, per byte [0,255])
** x = xyz coords 	(3 doubles, [<,>])
** v = vector 		(3 doubles, [-1,1])
** f = fov 			(int, [0,180])
** d = double 		(double, [<,>])
*/

const t_table			g_ident_table[9] = {
	{"R", 2, "ii"},
	{"A", 2, "rc"},
	{"c", 3, "xvf"},
	{"l", 3, "xrc"},
	{"sp", 3, "xdc"},
	{"pl", 3, "xvc"},
	{"sq", 4, "xvdc"},
	{"cy", 5, "xvddc"},
	{"tr", 4, "xxxc"}
};

static t_table			get_ident_info(char *ident)
{
	size_t	i;

	i = 0;
	while (i < sizeof(g_ident_table) / sizeof(t_table))
	{
		if (ft_strcmp(ident, g_ident_table[i].ident))
			return (g_ident_table[i]);
		i++;
	}
	return ((t_table){NULL, 0, NULL});
}

static size_t			ft_strlen_space(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && !ft_isspace(s[len]))
		len++;
	return (len);
}

static double			clamp_double(double num, double min, double max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}

static int				clamp_int(int num, int min, int max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}

char					*get_identifier(char *s)
{
	char	*ident;
	size_t	len;

	len = ft_strlen_space(s);
	ident = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ident, s, len + 1);
	return (ident);
}

double					get_double(char *s)
{
	//return (ft_atof(s));
	(void)s;
	return (0.0);
}

t_vec					get_vector(char *s)
{
	t_vec	vec;

	vec.x = get_double(s);
	vec.y = get_double(s);
	vec.z = get_double(s);
	return (vec);
}

double					get_ratio(char *s)
{
	double	dbl;

	dbl = get_double(s);
	if (dbl < 0.0 || dbl > 1.0)
		puterror(__FILE__, __LINE__, "ratio outside of 0.0-1.0");
	return (clamp_double(dbl, 0.0, 1.0));
}

unsigned int			get_num(char *s)
{
	int	num;

	num = ft_atoi(s);
	if (num < 0)
		puterror(__FILE__, __LINE__, "number less than 0");
	return (num);
}

int						get_fov(char *s)
{
	int	fov;

	fov = ft_atoi(s);
	if (fov < 0 || fov > 180)
		puterror(__FILE__, __LINE__, "fov outside of 0-180");
	return (clamp_int(fov, 0, 180));
}

int						get_color(char *s)
{
	int	color;

	color = clamp_int(ft_atoi(s), 0, 255);
	while (ft_isdigit(*s))
		s++;
	color = color << 4 & clamp_int(ft_atoi(s), 0, 255);
	while (ft_isdigit(*s))
		s++;
	color = color << 4 & clamp_int(ft_atoi(s), 0, 255);
	return (color);
}

t_field					*get_fields(char *line)
{
	t_field	*fields;
	char	*ident;
	t_table	ident_info;
	size_t	i;

	ident = get_identifier(line);
	ident_info = get_ident_info(ident);
	if (ident_info.num_fields == 0)
	{
		puterror(__FILE__, __LINE__, "invalid identifier");
		free(ident);
		return (NULL);
	}
	fields = malloc(sizeof(t_field) * (ident_info.num_fields + 1));
	i = 0;
	while (ident_info.field_types[i] != '\0')
	{
		if (ident_info.field_types[i] == 'i')
			fields[i].uint = get_num(line);
		if (ident_info.field_types[i] == 'r')
			fields[i].dbl = get_ratio(line);
		if (ident_info.field_types[i] == 'c')
			fields[i].color = get_color(line);
		if (ident_info.field_types[i] == 'x')
			fields[i].vec = get_vector(line);
		if (ident_info.field_types[i] == 'v')
			fields[i].vec = get_vector(line);
		if (ident_info.field_types[i] == 'f')
			fields[i].fov = get_fov(line);
		if (ident_info.field_types[i] == 'd')
			fields[i].dbl = get_double(line);
		i++;
	}
	return (fields);
}

t_mlx_data				*parse_lines(t_list *lines)
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
