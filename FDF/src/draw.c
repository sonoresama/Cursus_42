/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:58:07 by eorer             #+#    #+#             */
/*   Updated: 2023/02/27 12:57:17 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_coord	coord_to_plan(int x, int y, int z, t_vars *vars)
{
	t_coord	plan;

	plan.x = vars->start.x + (x - y) * vars->size;
	plan.y = vars->start.y + (x + y)
		* (vars->size * sin(vars->angel)) - z * vars->size_high;
	plan.z = 0;
	return (plan);
}

void	draw_grid(t_vars *vars, int **map, int len, unsigned int color)
{
	int		i;
	int		j;
	t_coord	a;
	t_coord	b;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (++i < len)
		{
			a = coord_to_plan(i, j, map[j][i], vars);
			if (i != len - 1)
			{
				b = coord_to_plan(i + 1, j, map[j][i + 1], vars);
				draw_line(vars, a, b, color);
			}
			if (map[j + 1])
			{
				b = coord_to_plan(i, j + 1, map[j + 1][i], vars);
				draw_line(vars, a, b, color);
			}
		}
	}
}
