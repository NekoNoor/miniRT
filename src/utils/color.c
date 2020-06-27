/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:17:16 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/26 15:45:54 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	pack_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	unpack_t(int trgb)
{
	return (trgb & 0xFF);
}

int	unpack_r(int trgb)
{
	return (trgb & 0xFF00);
}

int	unpack_g(int trgb)
{
	return (trgb & 0xFF0000);
}

int	unpack_b(int trgb)
{
	return (trgb & 0xFF000000);
}
