/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 14:13:58 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 17:13:03 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "renderer.h"
# include "libft.h"

typedef	struct	s_table
{
	const char	*ident;
	int			num_fields;
	const char	*field_types;
}				t_table;

typedef union	u_field
{
	t_vec		vec;
	double		ratio;
	int			fov;
	int			color;
	double		dbl;
	
}				t_field;

t_list			*get_lines(const char *path);
t_mlx_data		*parse_lines(t_list *lines);

#endif
