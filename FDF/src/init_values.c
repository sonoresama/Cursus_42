/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:16:25 by eorer             #+#    #+#             */
/*   Updated: 2023/03/20 15:22:21 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_size(t_vars *vars)
{
	t_coord	corner_a;
	t_coord	corner_b;

	corner_a = coord_to_plan(vars->length_map, vars->height_map, 0, vars);
	corner_b = coord_to_plan(0, vars->height_map, 0, vars);
	while (corner_b.x > vars->w_width || corner_b.y > vars->w_height
		|| corner_a.x > vars->w_width || corner_a.y > vars->w_height)
	{
		zoom_moins(vars);
		corner_a = coord_to_plan(vars->length_map, vars->height_map, 0, vars);
		corner_b = coord_to_plan(0, vars->height_map, 0, vars);
		vars->m_center = coord_to_plan(vars->length_map / 2 - 1,
				vars->height_map / 2 - 1, 0, vars);
		center_map(vars);
	}
	zoom_moins(vars);
	center_map(vars);
}

void	max_high(t_vars *vars, int *max)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (j < vars->length_map)
		{
			if (valeur_absolue(vars->map[i][j]) > *max)
				*max = valeur_absolue(vars->map[i][j]);
			j++;
		}
		i++;
	}
}

int	init_values(t_vars *vars, char *file_path)
{
	int	i;

	i = 0;
	vars->map = get_map(file_path, &vars->length_map);
	if (!vars->map)
		return (1);
	while (vars->map[i])
		i++;
	vars->height_map = i;
	vars->start = (t_coord){0, 0, 0};
	vars->size = 64;
	vars->high = 2;
	vars->size_high = (float)vars->size / vars->high;
	vars->max_high = 0;
	vars->angel = asin(0.5);
	vars->m_center = coord_to_plan(vars->length_map / 2 - 1,
			vars->height_map / 2 - 1, 0, vars);
	vars->w_center = (t_coord){vars->w_width / 2, vars->w_height / 2, 0};
	max_high(vars, &vars->max_high);
	center_map(vars);
	set_size(vars);
	adjust_height(vars);
	return (0);
}
