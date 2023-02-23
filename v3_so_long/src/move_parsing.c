/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:11:06 by eorer             #+#    #+#             */
/*   Updated: 2023/02/15 17:51:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	recursive(t_coord *pos, char **map, fp_move *ft)
{
	int	i;
	t_coord	reset;
	fp_move	func;

	if (map[pos->y][pos->x] == '1' || map[pos->y][pos->x] == 'X')
		return (1);
	if (map[pos->y][pos->x] == 'E')
		return (0);
	i = 0;
	reset = *pos;
	map[pos->y][pos->x] = 'X';
	while (i < 4)
	{
		func = ft[i];
		func(pos, map);
		
		if (recursive(pos, map, ft) == 0)
			return (0);
		*pos = reset;
		i++;
	}
	map[pos->y][pos->x] == '0';
	return (1);
}
