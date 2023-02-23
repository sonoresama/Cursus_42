/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:17 by eorer             #+#    #+#             */
/*   Updated: 2023/02/15 17:53:09 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//typedef int (*fp_move)(t_coord *pos, char **map);

int	move_up(t_coord *pos, char **map)
{
	pos->y = pos->y - 1;
	return (0);
}

int	move_down(t_coord *pos, char **map)
{
	pos->y = pos->y + 1;
	return (0);
}

int	move_left(t_coord *pos, char **map)
{
	pos->x = pos->x - 1;
	return (0);
}

int	move_right(t_coord *pos, char **map)
{
	pos->x = pos->x + 1;
	return (0);
}

int	parsing_map(t_coord player, char **map)
{
	t_coord	pos;
	fp_move	*ft;

	ft = (fp_move[4]){
		[0] = move_up, 
		[1] = move_down,
		[2] = move_left,
		[3] = move_right};
	pos = (t_coord){player.y, player.x};
	if (recursive(&pos, map, ft) == 1)
		return (1);
	return (0);
}
