/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:37:41 by eorer             #+#    #+#             */
/*   Updated: 2023/09/19 18:26:11 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"


int	keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int	render(void *ptr)
{
	(void)ptr;
	return (0);
}

int	main(void)
{
	t_data		data;
	t_ray		ray;
	t_pixel		pixel;
	t_sphere	sphere;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 800, 450, "MINI");
	if (!data.win)
		return (1);
	init_img(&data.mlx_img, &data.mlx, 800, 450);
	if (!data.mlx_img.img || !data.mlx_img.addr)
		return (1);
	data.img_width = 800;
	data.img_height = 450;
	data.cam_pos.x = 0;
	data.cam_pos.y = 0;
	data.cam_pos.z = 0;
	sphere.radius = 5;
	sphere.center[0] = 0;
	sphere.center[1] = 0;
	sphere.center[2] = 0;
	sphere.color[0] = 255;
	sphere.color[1] = 255;
	sphere.color[2] = 155;
	pixel.x = 0;
	pixel.y = 0;
	generate_ray(&ray, &data, pixel);
	printf("Origin : %f %f %f\n", ray.origin.x, ray.origin.y, ray.origin.z);
	printf("Direction : %f %f %f\n", ray.direction.x, ray.direction.y, ray.direction.z);
	ft_normalize(&ray.direction);
	printf("Normalized direction : %f %f %f\n", ray.direction.x, ray.direction.y, ray.direction.z);
//	draw_sphere(&data, &sphere);
//	mlx_put_image_to_window(data.mlx, data.win, data.mlx_img.img, 0, 0);
//	mlx_loop_hook(data.mlx, &render, &data);
//	mlx_hook(data.win, KeyPress, KeyPressMask, &keypress, &data);
//	mlx_loop(data.mlx);
//	mlx_destroy_image(data.mlx, data.mlx_img.img);
//	mlx_destroy_display(data.mlx);
//	free(data.mlx);
}
