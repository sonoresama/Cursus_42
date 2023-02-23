/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:22:14 by eorer             #+#    #+#             */
/*   Updated: 2023/02/09 10:58:39 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	move_up(t_vars *vars, t_coord pos)
{
	vars->map[pos.y][pos.x] = '0';
	vars->map[pos.y - 1][pos.x] = 'P';
	vars->player.pos = (t_coord){pos.y - 1, pos.x};
}

static void	move_left(t_vars *vars, t_coord pos)
{
	vars->map[pos.y][pos.x] = '0';
	vars->map[pos.y][pos.x - 1] = 'P';
	vars->player.pos = (t_coord){pos.y, pos.x - 1};
}

static void	move_down(t_vars *vars, t_coord pos)
{
	vars->map[pos.y][pos.x] = '0';
	vars->map[pos.y + 1][pos.x] = 'P';
	vars->player.pos = (t_coord){pos.y + 1, pos.x};
}

static void	move_right(t_vars *vars, t_coord pos)
{
	vars->map[pos.y][pos.x] = '0';
	vars->map[pos.y][pos.x + 1] = 'P';
	vars->player.pos = (t_coord){pos.y, pos.x + 1};
}

void	move_player(int key, t_vars *vars)
{
	t_coord	pos;

	pos = vars->player.pos;
	if (key == XK_w && vars->map[pos.y - 1][pos.x] != '1')
		move_up(vars, pos);
	else if (key == XK_a && vars->map[pos.y][pos.x - 1] != '1')
		move_left(vars, pos);
	else if (key == XK_s && vars->map[pos.y + 1][pos.x] != '1')
		move_down(vars, pos);
	else if (key == XK_d && vars->map[pos.y][pos.x + 1] != '1')
		move_right(vars, pos);
	if (vars->player.pos.x == vars->exit.pos.x && vars->player.pos.y == vars->exit.pos.y)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win= NULL;
	}
}
