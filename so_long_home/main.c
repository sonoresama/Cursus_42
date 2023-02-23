/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:34:08 by emileorer         #+#    #+#             */
/*   Updated: 2023/02/15 11:34:45 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "stdio.h"

int	parsing_map(t_coord player, char **map)
{
	t_coord last;
	t_corod	pos;

	last = (t_coord){0, 0, '0'};
	pos = (t_coord){player.y, player.x, 'P'};
	if (recursive(&pos, last, map) == 1)
		return (1);
	printf("ALL GOOD");
	return (0)
}

int	recursive(t_coord *pos, t_coord last, char **map)
{
	int	i;
	t_coord	reset;

	if (pos->value == '1')
		return (1);
	else if (pos->value == 'E')
		return (0);
	i = 0;
	reset = *pos;
	while (i < 4)
	{
		function[i](pos, map);
		if (last != *pos)
		{
			last = *pos;
			if (recursive(pos, last, map) == 0)
				return (0);
		}
		*pos = reset;
		i++;
	}
	return (1);
}

void	move_up(t_coord *pos, char **map)
{
	pos->y = pos->y - 1;
	pos->value = map[y][x];
}

void	move_down(t_coord *pos, char **map)
{
	pos->y = pos->y + 1;
	pos->value = map[y][x];
}

void	move_left(t_coord *pos, char **map)
{
	pos->x = pos->x - 1;
	pos->value = map[y][x];
}

void	move_right(t_coord *pos, char **map)
{
	pos->x = pos->x + 1;
	pos->value = map[y][x];
}
