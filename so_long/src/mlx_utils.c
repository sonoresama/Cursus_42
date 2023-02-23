/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:58:45 by eorer             #+#    #+#             */
/*   Updated: 2023/02/09 11:27:00 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	init_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int*)
			img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	init_img(t_img *img, void **mlx, int x, int y)
{
	img->img = mlx_new_image(*mlx, x, y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	init_img_xpm(t_vars *vars, t_img *img, char *file_path)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(vars->mlx, file_path, &width, &height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}


t_img	*get_texture(t_vars *vars, char value)
{
	if (value == '1')
		return (vars->border);
	else if (value == 'P')
		return (vars->player.img);
	else if (value == 'C')
		return (vars->item);
	else if (value == 'E')
		return (vars->exit.img);
	else
		return (vars->field);
}


