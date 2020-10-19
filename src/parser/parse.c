/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:09:32 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:18:20 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>

int				ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			break ;
		s2++;
		s1++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int		valid_ident(char *ident)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("R", ident))
		ret = 1;
	if (ft_strcmp("A", ident))
		ret = 1;
	if (ft_strcmp("c", ident))
		ret = 1;
	if (ft_strcmp("l", ident))
		ret = 1;
	if (ft_strcmp("sp", ident))
		ret = 1;
	if (ft_strcmp("pl", ident))
		ret = 1;
	if (ft_strcmp("cy", ident))
		ret = 1;
	if (ft_strcmp("tr", ident))
		ret = 1;
	return (ret);
}

static size_t	ft_strlen_space(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && !ft_isspace(s[len]))
		len++;
	return (len);
}

char		*get_identifier(char *s) // R,A,c,l,sp,pl,cy,tr
{
	char	*ident;
	size_t	len;

	len = ft_strlen_space(s);
	ident = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(ident, s, len + 1);
	if (!valid_ident(ident))
	{
		puterror(__FILE__, __LINE__, "invalid identifier");
		free(ident);
		return (NULL);
	}
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
 */

/*
 *char		**get_fields(char *line) // use above functions depending on identifier
 *{
 *    char	*ident;
 *
 *    ident = get_identifier(line);
 *    if (ft_strcmp(ident, "R") == 0)
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
