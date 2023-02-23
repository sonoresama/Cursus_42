/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_and_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:00:26 by eorer             #+#    #+#             */
/*   Updated: 2023/02/23 14:00:29 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	number_row_file(char *file_path)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(file_path, O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (i);
}

int	number_cols(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	return (i - 1);
}

int	number_row_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i][0] != '\n')
		i++;
	return (i);
}
