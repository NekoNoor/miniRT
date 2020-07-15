/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:08:44 by nschat        #+#    #+#                 */
/*   Updated: 2020/07/14 17:24:28 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "parser.h"

#include <stdio.h> //

int	main(int ac, char **av)
{
	t_mlx_data	*data;
	t_list		*lines;
	t_list		*copy; //

	if (ac < 2)
		return (1);
	lines = get_lines(av[1]);
	if (lines == NULL)
		return (1);
	copy = lines; //
	while (copy != NULL) //
	{
		printf("content: %s\n", (char *)copy->content); //
		copy = copy->next; //
	} //
	data = parse_lines(lines);
	render(data);
	return (0);
}
