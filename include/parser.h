/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/15 14:13:58 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/27 13:55:57 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "renderer.h"
# include "libft.h"

t_list		*get_lines(const char *path);
t_mlx_data	*parse_lines(t_list *lines);

#endif
