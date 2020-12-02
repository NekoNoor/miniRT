/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:21 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/10 18:35:34 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*orig;
	char		c_c;

	orig = s;
	c_c = (char)c;
	s += ft_strlen(s);
	while (s > orig && *s != c_c)
		s--;
	if (s == orig && *s != c_c)
		return (NULL);
	return ((char *)s);
}
