/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:01:43 by eorer             #+#    #+#             */
/*   Updated: 2023/02/21 14:29:19 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	center_x(t_vars *vars)
{
	while (vars->m_center.x != vars->w_center.x)
	{
		if (vars->m_center.x > vars->w_center.x)
		{
			vars->m_center.x--;
			vars->start.x--;
		}
		else if (vars->m_center.x < vars->w_center.x)
		{
			vars->m_center.x++;
			vars->start.x++;
		}
	}
}

void	center_y(t_vars *vars)
{
	while (vars->m_center.y != vars->w_center.y)
	{
		if (vars->m_center.y > vars->w_center.y)
		{
			vars->m_center.y--;
			vars->start.y--;
		}
		else if (vars->m_center.y < vars->w_center.y)
		{
			vars->m_center.y++;
			vars->start.y++;
		}
	}
}

void	center_map(t_vars *vars)
{
	if (vars->m_center.x == vars->w_center.x
		&& vars->m_center.y == vars->w_center.y)
		return ;
	center_x(vars);
	center_y(vars);
}
