/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:36:48 by eorer             #+#    #+#             */
/*   Updated: 2023/02/21 15:28:25 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

void	print_tab(int **tab, int length)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < length)
		{
			ft_printf(" %d", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tab(int **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*void	erase_img(t_vars *vars)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < vars->w_height)
	{
		i = 0;
		while (i < vars->w_width)
		{
			my_mlx_pixel_put(&vars->mlx_img, i, j, 0x00000000);
			i++;
		}
		j++;
	}
}*/

void	erase_img(t_vars *vars)
{
	draw_grid(vars, vars->map, vars->length_map, 0x00000000);
}
