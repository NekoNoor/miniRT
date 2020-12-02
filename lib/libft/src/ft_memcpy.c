/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:48:18 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/18 17:41:45 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_uc;
	unsigned const char	*src_ucc;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_uc = (unsigned char *)dst;
	src_ucc = (unsigned const char *)src;
	i = 0;
	if (dst < src)
		while (i < n)
		{
			dst_uc[i] = src_ucc[i];
			i++;
		}
	else
		while (n)
		{
			n--;
			dst_uc[n] = src_ucc[n];
		}
	return (dst);
}
