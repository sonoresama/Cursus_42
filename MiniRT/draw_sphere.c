/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:29:27 by eorer             #+#    #+#             */
/*   Updated: 2023/09/21 18:09:09 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_hiting_sphere(t_ray ray, t_sphere sphere)
{
	double	a;
	double	b;
	double	c;

	a = mult_vectors(ray.direction, ray.direction);
	b = mult_vectors(mult_const_vector(ray.direction, 2), sous_vectors(ray.origin, sphere.center));
	c = mult_vectors(sous_vectors(ray.origin, sphere.center), sous_vectors(ray.origin, sphere.center)) - pow(sphere.radius, 2);
	if (pow(b, 2) - 4 * a * c >= 0)
		return (1);
	return (0);
}

void	draw_sphere(t_data *data, t_sphere *sphere)
{
	int	i;
	int	j;
	t_ray	ray;

	i = 0;
	j = 0;
	while (i < data->img_width)
	{
		while (j < data->img_height)
		{
			generate_ray(&ray, data, (t_pixel){i, j});
			if (is_hiting_sphere(ray, *sphere))
				my_mlx_pixel_put(&data->mlx_img, i, j, init_color(0, 255, 255, 150));
			else
				my_mlx_pixel_put(&data->mlx_img, i, j, 0);
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	generate_ray(t_ray *ray, t_data *data, t_pixel pixel)
{
	float	x_norm;
	float	y_norm;
	t_vect	pixel_cam;

	if (!data->img_height)
	{
		printf("Height = 0\n");
		return ;
	}
	x_norm = (pixel.x + 0.5) / data->img_width;
	y_norm = (pixel.y + 0.5) / data->img_height;
		// this is assuming img_width > img_height
	pixel_cam.x = (2 * x_norm - 1) * data->screen.aspect_ratio * tan(rad((data->camera.fov / 2))); 
	pixel_cam.y = (1 - 2 * y_norm) * tan(rad((data->camera.fov / 2))); 
	pixel_cam.z = -1.0;
	ray->origin = data->camera.pos;
//	print_vect(pixel_cam);
//	pixel_cam = rotate_cam(data->fov / 2, 1, pixel_cam);
//	pixel_cam = rotate_cam(data->fov / 2, 2, pixel_cam);
//	pixel_cam = rotate_cam(data->fov / 2, 3, pixel_cam);
//	pixel_cam = add_vectors(pixel_cam, data->camera->pos);
//	print_vect(pixel_cam);
	ray->direction = sous_vectors(pixel_cam, ray->origin);
	ft_normalize(&ray->direction);
	return ;
}
