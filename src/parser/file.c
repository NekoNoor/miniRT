/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 12:31:42 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/15 18:38:57 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	**get_lines(const char *path)
{
	unsigned long	i;
	char			**lines;
	int				ret;
	int				fd;

	fd = open(path, O_RDONLY);
	lines = (char **)malloc(sizeof(char *) * linecount);
	ret = 1;
	i = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, lines + i);
		i++;
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}
