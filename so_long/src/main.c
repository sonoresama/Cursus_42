/* ************************************************************************** */
/*                                                                            */
/*e                                                       :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:16:05 by eorer             #+#    #+#             */
/*   Updated: 2023/02/09 10:49:49 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

#define WIDTH 800
#define HEIGHT 600

void	free_map(char **map);

int	is_movement(int keycode)
{
	if (keycode == XK_w || keycode == XK_a)
		return (1);
	else if (keycode == XK_s || keycode == XK_d)
		return (1);
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	else if (is_movement(keycode))
		move_player(keycode, vars);
	return (0);
}

int	render(t_vars *vars)
{
	if (!vars->win)
		return (1);
	put_map_on_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	**map;
	int	len_line;

	init_game(&vars, &len_line);
	if (!vars.map)
		return (1);

	print_map(&vars);

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, SIZE_SQR * len_line, SIZE_SQR * number_row(FILE_PATH), "TEST");
	if (!vars.win)
	{
		free(vars.mlx);
		return (1);
	}
	init_img(&vars.img, &vars.mlx, SIZE_SQR * len_line, SIZE_SQR * number_row(FILE_PATH));
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &keypress, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.img.img);
	free(vars.mlx);
	free_map(vars.map);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
