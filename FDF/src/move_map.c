/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:46:39 by eorer             #+#    #+#             */
/*   Updated: 2023/02/23 16:31:05 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_map(t_vars *vars, int keycode)
{
	erase_img(vars);
	if (keycode == XK_Up)
	{
		vars->start.y += SPEED_MOVE;
		vars->w_center = (t_coord){vars->w_center.x,
			vars->w_center.y + SPEED_MOVE, 0};
	}
	else if (keycode == XK_Down)
	{
		vars->start.y -= SPEED_MOVE;
		vars->w_center = (t_coord){vars->w_center.x,
			vars->w_center.y - SPEED_MOVE, 0};
	}
	else if (keycode == XK_Left)
	{
		vars->start.x += SPEED_MOVE;
		vars->w_center = (t_coord){vars->w_center.x + SPEED_MOVE,
			vars->w_center.y, 0};
	}
	else
	{
		vars->start.x -= SPEED_MOVE;
		vars->w_center = (t_coord){vars->w_center.x - SPEED_MOVE,
			vars->w_center.y, 0};
	}
}
