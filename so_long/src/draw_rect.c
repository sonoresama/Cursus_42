/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:52:26 by eorer             #+#    #+#             */
/*   Updated: 2023/02/14 09:52:58 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	draw_rect(t_vars *vars, t_coord pos, char value)
{
	int	i;
	int	j;
	t_img	*img;
	unsigned int	color;

	img = get_texture(vars, value);
	i = pos.x;
	while (i < pos.x + SIZE_SQR)
	{
		j = pos.y;
		while (j < pos.y + SIZE_SQR)
		{
			color = mlx_get_pixel(img, i - pos.x, j - pos.y);
			my_mlx_pixel_put(&vars->img, i, j, color);
			j++;
		}
		i++;
	}
	return (0);
}
