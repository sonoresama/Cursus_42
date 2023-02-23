/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:48:29 by eorer             #+#    #+#             */
/*   Updated: 2023/02/14 16:14:16 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_background(t_vars *vars)
{
	int	i;
	int	j;
	t_coord	pos;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j])
		{
			pos = (t_coord){j * SIZE, i * SIZE};
			if (vars->map[i][j] == '1')
				draw_png(vars, &vars->border.img, pos);
			else
				draw_png(vars, &vars->field.img, pos);
			j++;
		}
		i++;
	}
}

void	render_background_rect(t_vars *vars)
{
	int	i;
	int	j;
	t_coord	pos;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j])
		{
			pos = (t_coord){j * SIZE, i * SIZE};
			if (vars->map[i][j] == '1')
				draw_rect(vars, pos, 0X00FF00);
			else
				draw_rect(vars, pos, 0X0000FF);
			j++;
		}
		i++;
	}
}
