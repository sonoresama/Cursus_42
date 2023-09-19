/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:38:21 by eorer             #+#    #+#             */
/*   Updated: 2023/09/19 18:25:52 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

// MACROS //

// STRUCTURES //

typedef unsigned int	t_ui;

typedef struct	s_pixel{
	int	x;
	int	y;
}	t_pixel;

typedef struct	s_vect{
	float	x;
	float	y;
	float	z;
}	t_vect;

typedef struct	s_ray{
	t_vect	origin;
	t_vect	direction;
}	t_ray;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef	struct	s_sphere{
	int	center[3];
	int	color[3];
	int	radius;
}	t_sphere;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	mlx_img;
	int	img_width;
	int	img_height;
	int	fov;
	t_vect	cam_pos;
}	t_data;

// FONCTIONS PROGRAM //

void	draw_sphere(t_data *data, t_sphere *sphere);
void	generate_ray(t_ray *ray, t_data *data, t_pixel origin);

// FONCTIONS UTILITIES //

void	ft_normalize(t_vect *vector);

// FONCTIONS MLX //

int	init_color(int t, int r, int g, int b);
t_ui	mlx_get_pixel(t_img *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_img(t_img *img, void **mlx, int x, int y);

#endif
