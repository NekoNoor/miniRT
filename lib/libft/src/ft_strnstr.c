/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 17:06:11 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/24 15:59:31 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	needlelen = ft_strlen(needle);
	i = 0;
	while (len - i >= needlelen)
	{
		if (*haystack == '\0')
			break ;
		if (ft_strncmp(haystack, needle, needlelen) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
