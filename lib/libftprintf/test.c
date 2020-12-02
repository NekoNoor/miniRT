/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 18:06:31 by nschat        #+#    #+#                 */
/*   Updated: 2020/02/21 12:10:57 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"
#include <stdio.h>
#include <stdarg.h>

void	pf_test(const char *format, ...)
{
	va_list	ft_ap;
	va_list	bsd_ap;
	int		ft_len;
	int		bsd_len;

	puts("--------------");
	va_start(ft_ap, format);
	va_copy(bsd_ap, ft_ap);
	ft_len = ft_vprintf(format, ft_ap);
	va_end(ft_ap);
	putchar('\n');
	bsd_len = vprintf(format, bsd_ap);
	va_end(bsd_ap);
	putchar('\n');
	if (ft_len != bsd_len)
		puts("--------------\n[\e[41m!!!\e[0m]");
	else
		puts("--------------");
	printf("format: %s\nft_len: %i\nbsd_len: %i\n\n", format, ft_len, bsd_len);
}

int		main(void)
{
	pf_test("%7u", 33);
	pf_test("%7x", 33);
	pf_test("%c%7u", 0x41, 33);
	pf_test("c%-7u", 33);
	pf_test("[%7u]", 33);
	pf_test("%3u", 75);
	pf_test("c%7u", 33);
	pf_test("%-*.*s", -7, -3, "yolo");
	pf_test("%0*i", -7, -54);
	pf_test("%");
	pf_test("%5");
	pf_test("%05");
	pf_test("%-05");
	pf_test("%-5");
	pf_test("");
	return (0);
}
