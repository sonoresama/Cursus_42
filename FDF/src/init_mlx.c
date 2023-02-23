/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:24:10 by eorer             #+#    #+#             */
/*   Updated: 2023/02/22 12:06:22 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		perror("ERREUR");
		return (1);
	}
	vars->w_width = W_WIDTH;
	vars->w_height = W_HEIGHT;
	vars->win = mlx_new_window(vars->mlx, vars->w_width, vars->w_height, "FDF");
	if (!vars->win)
	{
		free(vars->mlx);
		perror("ERREUR");
		return (1);
	}
	init_img(&vars->mlx_img, &vars->mlx, vars->w_width, vars->w_height);
	return (0);
}
