/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 17:38:26 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/18 19:26:43 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*ft_memset_char(void *b, int c, size_t len)
{
	unsigned char	*b_uc;
	unsigned char	c_uc;

	b_uc = (unsigned char *)b;
	c_uc = (unsigned char)c;
	while (len)
	{
		len--;
		b_uc[len] = c_uc;
	}
	return (b);
}

static unsigned int	ft_repeat_bytes(int c)
{
	unsigned int	uint;

	uint = (unsigned char)c;
	if (uint != 0)
	{
		uint = (uint << 8) | uint;
		uint = (uint << 16) | uint;
	}
	return (uint);
}

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned int	uint;
	unsigned char	*dst;

	dst = b;
	uint = ft_repeat_bytes(c);
	n = (long)dst & (SIZE - 1);
	if (n)
	{
		n = SIZE - n;
		len -= n;
		ft_memset_char(dst, c, n);
		dst += n;
	}
	n = len / SIZE;
	while (n)
	{
		*(unsigned int *)dst = uint;
		dst += SIZE;
		n--;
	}
	n = len & (SIZE - 1);
	if (n)
		ft_memset_char(dst, c, n);
	return (b);
}
