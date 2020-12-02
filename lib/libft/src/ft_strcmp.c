/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:27:39 by nschat        #+#    #+#                 */
/*   Updated: 2019/12/04 17:21:13 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			break ;
		s2++;
		s1++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
