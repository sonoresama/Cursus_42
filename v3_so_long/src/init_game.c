/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:16:20 by eorer             #+#    #+#             */
/*   Updated: 2023/02/15 15:44:32 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_mlx(t_vars *vars)
{
	int	col;
	int	row;

	row = 0;
	col = ft_strlen(vars->map[1]) - 1;
	while (vars->map[row])
		row++;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, SIZE * col, SIZE * row, "GAME");
	if (!vars->win)
	{
		free(vars->mlx);
		return (1);
	}
	init_img(&vars->img, &vars->mlx, SIZE * col, SIZE * row);
	if (!vars->img.img)
		return (1);
	return (0);
}

void	init_player_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				vars->player.pos = (t_coord){i, j};
			else if (vars->map[i][j] == 'E')
				vars->exit.pos = (t_coord){i, j};
			j++;
		}
		i++;
	}
}

int	init_game(t_vars *vars, char *map_path)
{
	vars->map = init_map(map_path);
	if (!vars->map)
		return (1);
	print_map(vars->map);
	if (init_mlx(vars) == 1)
		return (1);
	init_player_exit(vars);
	return (0);
}

