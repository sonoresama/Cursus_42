/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:55:22 by eorer             #+#    #+#             */
/*   Updated: 2023/02/23 16:30:15 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(t_vars *vars, int keycode)
{
	erase_img(vars);
	if (keycode == XK_u)
		zoom_plus(vars);
	else
		zoom_moins(vars);
	vars->m_center = coord_to_plan(vars->length_map / 2 - 1,
			vars->height_map / 2 - 1, 0, vars);
}

void	zoom_plus(t_vars *vars)
{
	if (vars->size < ZOOM)
	{
		vars->size++;
		vars->start.x++;
		vars->start.y++;
	}
	else
	{
		vars->size += ZOOM;
		vars->start.x -= ZOOM;
		vars->start.y -= ZOOM;
	}
	vars->size_high = (float)vars->size / vars->high;
}

void	zoom_moins(t_vars *vars)
{
	if (vars->size < 1)
		return ;
	else if (vars->size - ZOOM <= 0)
	{
		vars->size--;
		vars->start.x--;
		vars->start.y--;
	}
	else
	{
		vars->size -= ZOOM;
		vars->start.x += ZOOM;
		vars->start.y += ZOOM;
	}
	vars->size_high = (float)vars->size / vars->high;
}
