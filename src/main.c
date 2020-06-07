/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:08:44 by nschat        #+#    #+#                 */
/*   Updated: 2020/05/27 13:08:59 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	char		*filecontents;
	t_something	*parsed_rt;
	char		**lines;

	if (ac > 1)
		filecontents = read_file(av[1]);
	lines = split_lines(filecontents);
	parsed_rt = parse(lines);
	if (ac > 2 && ft_strcmp(av[2], "--save") == 0)
		render_to_file(parsed_rt);
	render_window(parsed_rt);
}
