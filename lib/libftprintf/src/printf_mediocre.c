/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 15:30:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:06:11 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_pflist	*list;
	int		len;

	list = analyze_format(fd, format, ap);
	len = print_list(list);
	free_list(&list);
	return (len);
}

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vdprintf(1, format, ap);
	va_end(ap);
	return (len);
}
