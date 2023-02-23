/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mobile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:37:38 by eorer             #+#    #+#             */
/*   Updated: 2023/02/16 15:13:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_player(t_vars *vars)
{
	t_coord	pos;

	pos = (t_coord){vars->player.pos.x * SIZE, vars->player.pos.y * SIZE};
	draw_png(vars, &vars->player.img, pos);	
}

void	render_exit(t_vars *vars)
{
	t_coord	pos;

	pos = (t_coord){vars->exit.pos.x * SIZE, vars->exit.pos.y * SIZE};
	draw_png(vars, &vars->exit.img, pos);	
}

/*void	render_items(t_vars *vars)
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
			if (vars->map[i][j] == 'C')
			{
				pos = (t_coord){j * SIZE, i * SIZE};
				draw_png(vars, &vars->item.img, pos);
			}
			j++;
		}
		i++;
	}
}*/

void	render_mobile(t_vars *vars)
{
	render_player(vars);
	render_exit(vars);
//	render_items(vars);
}
