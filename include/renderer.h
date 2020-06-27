/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 09:49:34 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/26 16:46:01 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

typedef struct	s_mlx_data
{
	unsigned int	width;
	unsigned int	height;
	void			*mlx;
	void			*win;
	void			*img;
	char			*buf;
	int				bpp;
	int				size_line;
	int				endian;
}				t_mlx_data;

void			render(t_mlx_data *data);

#endif
