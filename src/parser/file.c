/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 12:31:42 by nschat        #+#    #+#                 */
/*   Updated: 2020/09/10 00:36:44 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "error.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h> //

static int	check_extension(const char *path)
{
	int	ret;

	ret = 1;
	while (*path != '\0')
		path++;
	if (ft_strlen(path) < 3 && 
			(*(path - 3) != '.' || *(path - 2) != 'r' || *(path - 1) != 't'))
		ret = 0;
	return (ret);
}

t_list		*get_lines(const char *path)
{
	t_list			*head;
	char			*line;
	int				ret;
	int				fd;

	if (check_extension(path) == 0)
	{
		puterror("File extension is not \".rt\"");
		exit(1);
	}
	head = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		puterror("");
		perror(NULL);
		exit(1);
	}
	ret = 1;
	while (ret == 1)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		printf("ret: %i, line: %s\n", ret, line); //
		if (ret == 1)
			ft_lstadd_back(&head, ft_lstnew(line));
	}
	close(fd);
	return (head);
}
