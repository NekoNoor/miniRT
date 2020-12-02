/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:19 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/18 17:41:01 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s1_ucc;
	unsigned const char	*s2_ucc;

	s1_ucc = (unsigned const char *)s1;
	s2_ucc = (unsigned const char *)s2;
	while (n)
	{
		if (*s1_ucc != *s2_ucc)
			return (*s1_ucc - *s2_ucc);
		s1_ucc++;
		s2_ucc++;
		n--;
	}
	return (0);
}
