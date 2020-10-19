/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   puterror.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 00:25:41 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:16:24 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"
#include "libft.h"
#include <unistd.h>

void	puterror(const char *file, size_t line, const char *message)
{
	size_t	len;

	len = ft_strlen(message);
	ft_dprintf(0, "Error\n");
	if (len > 0)
		ft_dprintf(0, "%s: %i: %s\n", file, line, message);
}
