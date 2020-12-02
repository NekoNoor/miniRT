/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:20 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/09 15:28:25 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*ptr;

	if (dst == NULL && src == NULL)
		return (0);
	ptr = ft_memccpy(dst, src, '\0', dstsize);
	if (ptr == NULL && dstsize)
		dst[dstsize - 1] = '\0';
	return (ft_strlen(src));
}
