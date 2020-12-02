/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_str.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 16:41:46 by nschat        #+#    #+#                 */
/*   Updated: 2020/01/29 16:42:13 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_uc;
	unsigned const char	*src_ucc;
	size_t				i;

	dst_uc = (unsigned char *)dst;
	src_ucc = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		dst_uc[i] = src_ucc[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start >= ft_strlen(s))
		return (NULL);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
