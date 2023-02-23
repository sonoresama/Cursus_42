/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:34:48 by eorer             #+#    #+#             */
/*   Updated: 2023/02/23 15:56:34 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int	keypress(int keycode, t_vars *vars)
{
	manage_event(vars, keycode);
	if (!vars->win)
		return (0);
	draw_grid(vars, vars->map, vars->length_map, 0x00FFFFFF);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mlx_img.img, 0, 0);
	return (0);
}

int	client_message(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	return (0);
}

int	render(t_vars *vars)
{
	if (!vars->win)
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_arg(argc, argv[1]))
		return (1);
	if (init_mlx(&vars))
		return (1);
	if (init_values(&vars, argv[1]))
		return (1);
	draw_grid(&vars, vars.map, vars.length_map, 0x00FFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.mlx_img.img, 0, 0);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &keypress, &vars);
	mlx_hook(vars.win, ClientMessage, StructureNotifyMask,
		&client_message, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.mlx_img.img);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free_tab(vars.map);
	return (0);
}
