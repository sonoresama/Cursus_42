/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:58:45 by eorer             #+#    #+#             */
/*   Updated: 2023/02/16 16:11:01 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	//ft_printf("LINE : %d\n", img->line_length);
	//ft_printf("BPP : %d\n", img->bits_per_pixel);
	//ft_printf("X : %d\n", x);
	//ft_printf("Y : %d\n\n", y);
	//int		txt_x;
	//int		txt_y;
	//char	*color;

	//txt_x = 0;
	//txt_y = 0;
	//txt_x = 64 / (100 / (((double)x / 64) * 100.0));
	//txt_y = 64 / (100 / (((double)y / 64) * 100.0));
	//color = img->addr + ((4 * 64 * txt_y) + (4 * txt_x));
	//return (color);
	return (*(unsigned int *)img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
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
	/*if (!img->img)
		return ;*/
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	init_img_xpm(t_img *img, void *mlx, char *file_path, int *width, int *height)
{
	img->img = mlx_xpm_file_to_image(mlx, file_path, width, height);
	if (!img->img)
	{
		ft_printf("ERREUR FDP \n\n");
		return ;
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->img)
	{
		ft_printf("ERREUR ADDR FDP \n\n");
		return ;
	}
}


/*t_img	*get_texture(t_vars *vars, char value)
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
}*/
