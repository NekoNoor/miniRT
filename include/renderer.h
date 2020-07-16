/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/25 09:49:34 by nschat        #+#    #+#                 */
/*   Updated: 2020/07/16 18:30:01 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

typedef	struct	s_mlx_img
{
	void	*img;
	char	*buf;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx_img;

typedef struct	s_mlx_data
{
	unsigned int	width;
	unsigned int	height;
	void			*mlx;
	void			*win;
	t_mlx_img		img;
}				t_mlx_data;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_ray
{
	t_vec	orig;
	t_vec	dir;
}				t_ray;

typedef struct	s_a
{
	double	ratio;
	int		color;
}				t_a;

typedef struct	s_c
{
	t_vec	center;
	t_vec	normal;
	int		hfov;
}				t_c;

typedef struct	s_l
{
	t_vec	center;
	double	brightness;
	int		color;
}				t_l;

typedef struct	s_sp
{
	t_vec	center;
	double	diameter; // double	radius; ??
	int		color;
}				t_sp;

typedef struct	s_pl
{
	t_vec	center;
	t_vec	normal;
	int		color;
}				t_pl;

typedef struct	s_sq
{
	t_vec	center;
	t_vec	normal;
	double	size;
	int		color;
}				t_sq;

typedef struct	s_cy
{
	t_vec	center;
	t_vec	normal;
	double	diameter; // double  radius; ??
	double	height;
	int		color;
}				t_cy;

typedef struct	s_tr
{
	t_vec	point1;
	t_vec	point2;
	t_vec	point3;
	int		color;
}				t_tr;

typedef union	u_obj
{
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_tr	tr;
}				t_obj;

typedef struct	s_objects
{
	char				*identifier;
	t_obj				obj;
	struct s_objects	*next;
}				t_objects;

void			render(t_mlx_data *data);

#endif
