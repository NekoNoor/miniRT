/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:08:44 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/27 14:05:53 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include "parser.h"
#include "renderer.h"

int	main(int ac, char **av)
{
	t_mlx_data	*data;
	t_list		*lines;
	t_list		*copy; //

	if (ac < 2)
		return (1);
	lines = get_lines(av[1]);
	copy = lines; //
	while (copy != NULL) //
	{
		printf("%s\n", (char *)copy->content); //
		copy = copy->next; //
	} //
	data = parse_lines(lines);
	render(data);
	return (0);
}
