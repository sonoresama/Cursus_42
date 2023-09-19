/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:29:27 by eorer             #+#    #+#             */
/*   Updated: 2023/09/19 18:24:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

typedef struct	s_screen{
	float	focal_length;//distance entre l'observateurice et le screen
	float	width;
	float	height;
}	t_screen;

void	draw_sphere(t_data *data, t_sphere *sphere)
{
	(void)data;
	(void)sphere;
	return ;
}

void	generate_ray(t_ray *ray, t_data *data, t_pixel origin)
{
	t_screen screen;
	float	x_norm;
	float	y_norm;
	t_vect	pixel_cam;
	float	img_ratio;

	if (!data->img_height)
	{
		printf("Height = 0\n");
		return ;
	}
	img_ratio = data->img_width / data->img_height;
	screen.focal_length = 1.0;
	screen.width = 2.0;
	screen.height = screen.width * img_ratio;
	x_norm = (origin.x + 0.5) / data->img_width;
	y_norm = (origin.y + 0.5) / data->img_height;
	pixel_cam.x = (2 * x_norm - 1) * img_ratio * tan((data->fov / 2) * (M_PI / 180)); 
	pixel_cam.y = (1 - 2 * y_norm) * tan((data->fov / 2) * (M_PI / 180)); 
	pixel_cam.z = -1.0;
	ray->origin = data->cam_pos;
	ray->direction.x = pixel_cam.x - ray->origin.x;
	ray->direction.y = pixel_cam.y - ray->origin.y;
	ray->direction.z = pixel_cam.z - ray->origin.z;
	return ;
}
