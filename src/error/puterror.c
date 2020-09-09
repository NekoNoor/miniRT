/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   puterror.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 00:25:41 by nschat        #+#    #+#                 */
/*   Updated: 2020/09/10 00:37:49 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	puterror(const char *message)
{
	size_t	len;

	len = ft_strlen(message);
	write(0, "Error\n", 6);
	if (len > 0)
	{
		write(0, message, len);
		write(0, "\n", 1);
	}
}
