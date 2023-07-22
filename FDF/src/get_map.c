/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:30:20 by eorer             #+#    #+#             */
/*   Updated: 2023/03/20 17:02:46 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

char	**init_map(char *map_path)
{
	char	**map;
	int		fd;
	int		i;
	int		n_row;

	n_row = number_row_file(map_path);
	i = -1;
	map = (char **)malloc(sizeof(char *) * (n_row + 1));
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDWR);
	if (fd == -1)
	{
		free(map);
		perror("ERROR");
		return (NULL);
	}
	while (++i < n_row)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	return (map);
}

int	is_coma(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	*atoi_split(char **split, int *length_map)
{
	int		i;
	int		*tab;
	char	**test;

	if (!split)
		return (NULL);
	i = 0;
	*length_map = number_row_map(split);
	tab = (int *)malloc(sizeof(int) * (*length_map));
	if (!tab)
		return (NULL);
	while (split[i] && split[i][0] != '\n')
	{
		if (is_coma(split[i]))
		{
			test = ft_split(split[i], ",");
			tab[i] = ft_atoi(test[0]);
			free_map(test);
		}
		else
			tab[i] = ft_atoi(split[i]);
		i++;
	}
	return (tab);
}

int	**map_to_int(char **map, int *length_map)
{
	int		n_row;
	char	**split;
	int		**tab;
	int		i;

	n_row = number_row_map(map);
	tab = (int **)malloc(sizeof(int *) * (n_row + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (map[i])
	{
		split = ft_split(map[i], "\n ");
		tab[i] = atoi_split(split, length_map);
		free_map(split);
		if (!tab[i] || !split)
		{
			free_tab(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	**get_map(char *file_path, int *length_map)
{
	char	**map;
	int		**tab;

	map = init_map(file_path);
	if (!map)
		return (NULL);
	tab = map_to_int(map, length_map);
	if (!tab)
		return (NULL);
	free_map(map);
	return (tab);
}
