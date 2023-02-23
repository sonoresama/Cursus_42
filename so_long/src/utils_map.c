/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:40:14 by eorer             #+#    #+#             */
/*   Updated: 2023/02/09 10:54:52 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#define PATH 

/*int	put_rect_on_win(t_vars *vars, t_case pos)
{
	t_rect	rect;

	rect = (t_rect){pos.x, pos.y, SIZE_SQR, SIZE_SQR, 0x00000000};
	if (pos.value == '1')
		rect.color = 0x00FFFFFF;
	if (pos.value == 'E')
		rect.color = 0x00CC0F00;
	else if (pos.value == 'P')
		rect.color = 0x00AAAA88;
	else if (pos.value == 'C')
		rect.color = 0x00FFFF00;
	draw_rect(vars, &vars->img, rect);
	return (0);
}*/

int	put_map_on_img(t_vars *vars)
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
			pos.x = j * SIZE_SQR;
			pos.y = i * SIZE_SQR;
			//pos.x = j * SIZE_SQR;
			//pos.y = i * SIZE_SQR;
			draw_rect(vars, pos, vars->map[i][j]);
	//		put_rect_on_win(vars, pos);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_map(t_vars *vars)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (vars->map[i])
	{
		ft_printf("%s", vars->map[i]);
		i++;
	}
}
