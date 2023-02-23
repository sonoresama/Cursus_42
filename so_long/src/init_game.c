/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:34:33 by eorer             #+#    #+#             */
/*   Updated: 2023/02/09 11:25:42 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	number_row(char *file_path)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(FILE_PATH, O_RDWR);
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

void	init_player(t_vars *vars)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->player.pos.x = j;
				vars->player.pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	init_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j])
		{
			if (vars->map[i][j] == 'E')
			{
				vars->exit.pos.x = j;
				vars->exit.pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	init_texture(t_vars *vars)
{
	init_img_xpm(vars, vars->border, "./images/border.xpm");
	init_img_xpm(vars, vars->field, "./images/field.xpm");
	init_img_xpm(vars, vars->item, "./images/field.xpm");
	init_img_xpm(vars, vars->player.img, "./images/player.xpm");
	init_img_xpm(vars, vars->exit.img, "./images/exit.xpm");
}
/*void	init_texture(t_vars *vars)
{
	vars->border = mlx_xpm_file_to_image(vars->mlx, "./images/border.xpm", &width, &height);
	vars->field = mlx_xpm_file_to_image(vars->mlx, "./images/field.xpm", &width, &height);
	vars->item = mlx_xpm_file_to_image(vars->mlx, "./images/item.xpm", &width, &height);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, "./images/player.xpm", &width, &height);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "./images/exit.xpm", &width, &height);
}*/

char	**init_map(int *len_line)
{
	int	fd;
	int	n_row;
	int	i;
	char	**map;

	n_row = number_row(FILE_PATH);
	fd = open(FILE_PATH, O_RDWR);
	map = malloc(sizeof(char *) * (n_row + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < n_row)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	*len_line = (int)ft_strlen(map[i - 1]) - 1;
	map[i] = NULL;
	close(fd);
	return (map);
}

int	init_game(t_vars *vars, int *len_line)
{
	vars->map = init_map(len_line);
	if (!vars->map)
		return (1);
	init_player(vars);
	init_exit(vars);
	init_texture(vars);
}

