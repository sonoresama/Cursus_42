/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:50 by eorer             #+#    #+#             */
/*   Updated: 2023/02/15 15:45:48 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**init_map(char *map_path)
{
	char	**map;
	int	fd;
	int	i;
	int	n_row;

	n_row = number_rows(map_path);
	i = -1;
	map = (char **)malloc(sizeof(char *) * (n_row + 1));
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDWR);
	while (++i < n_row)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}
