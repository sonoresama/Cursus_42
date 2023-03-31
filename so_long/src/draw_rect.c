/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:37:44 by eorer             #+#    #+#             */
/*   Updated: 2023/02/16 16:54:55 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	draw_png(t_vars *vars, t_img *img, t_coord pos)
{
	int	i;
	int	j;
	unsigned int	color;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			//color = mlx_get_pixel(img, j, i);
			color = mlx_get_pixel(img, 0, 0);
			//color = 0x00FF0000;
			my_mlx_pixel_put(&vars->img, j + pos.y, i + pos.x, color);
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_rect(t_vars *vars, t_coord pos, unsigned int color)
{
	int	i;
	int	j;

	i = pos.x;
	while (i < pos.x + SIZE)
	{
		j = pos.y;
		while (j < pos.y + SIZE)
		{
			my_mlx_pixel_put(&vars->img, j, i, color);
			j++;
		}
		i++;
	}
	return (0);
}
