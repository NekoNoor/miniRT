/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 12:31:42 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/27 13:55:39 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

t_list	*get_lines(const char *path)
{
	t_list			*head;
	char			*line;
	int				ret;
	int				fd;

	head = NULL;
	fd = open(path, O_RDONLY);
	ret = 1;
	while (ret == 1)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	close(fd);
	return (head);
}
