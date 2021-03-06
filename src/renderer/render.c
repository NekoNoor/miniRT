/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 08:53:28 by nschat        #+#    #+#                 */
/*   Updated: 2020/07/16 18:31:32 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include <stdlib.h>
#include <mlx.h>

#include <stdio.h> //

void	render(t_mlx_data *data)
{
	unsigned int	x;
	unsigned int	y;
	int				*int_buf;

	printf("width: %i\nheight: %i\n", data->width, data->height); //
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "miniRT");
	data->img.img = mlx_new_image(data->mlx, data->width, data->height);
	data->img.buf = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.size_line, &data->img.endian);
	int_buf = (int *)data->img.buf;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			int_buf[x + y * (data->img.size_line / sizeof(int))] = 0x00FF7F2A; //pack_trgb(0, 0xFF, 0x7F, 0x2A);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	// mlx_hook(data->win, 17, 0, &cleanly_exit, data);
	mlx_loop(data->mlx);
}
