/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 13:08:44 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/15 15:37:58 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include "parser.h"

int	main(int ac, char **av)
{
	char	**lines;

	if (ac < 2)
		return (1);
	lines = get_lines(av[1]);
	while (lines)
	{
		printf("%s\n", *lines);
		lines++;
	}
	return (0);
}
