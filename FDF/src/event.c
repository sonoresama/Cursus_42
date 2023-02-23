/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:39:24 by eorer             #+#    #+#             */
/*   Updated: 2023/02/23 16:25:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_vert(t_vars *vars, int keycode)
{
	erase_img(vars);
	if (keycode == XK_i)
		vars->angel += 0.1;
	else
		vars->angel -= 0.1;
	vars->m_center = coord_to_plan(vars->length_map / 2 - 1,
			vars->height_map / 2 - 1, 0, vars);
	center_map(vars);
}

void	manage_event(t_vars *vars, int keycode)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	else if (keycode == XK_w || keycode == XK_s)
		upgrade_height(vars, keycode);
	else if (keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_Left || keycode == XK_Right)
		move_map(vars, keycode);
	else if (keycode == XK_u || keycode == XK_j)
		zoom(vars, keycode);
	else if (keycode == XK_i || keycode == XK_k)
		rotate_vert(vars, keycode);
}
