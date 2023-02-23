/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:02:50 by eorer             #+#    #+#             */
/*   Updated: 2023/02/16 16:53:10 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define MAP_PATH "maps/test.ber"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	//else
	//	move_player(vars, keycode);
	return (0);
}

int	render(t_vars *vars)
{
	t_coord	pos;

	pos = (t_coord){vars->player.pos.x * SIZE, vars->player.pos.y * SIZE};
	if (vars->win)
	{
	//	render_background_rect(vars);
		//render_mobile(vars);
	//	draw_png(vars, &vars->player.img, pos);
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	//	mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img.img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	if (init_game(&vars, MAP_PATH) == 1)
		return (1);
	init_img_xpm(&vars.player.img, vars.mlx, "./images/player.xpm", &vars.player.dim.x, &vars.player.dim.y);
	init_img_xpm(&vars.exit.img, vars.mlx, "./images/exit.xpm", &vars.exit.dim.x, &vars.exit.dim.y);
	init_img_xpm(&vars.border.img, vars.mlx, "./images/border.xpm", &vars.border.dim.x, &vars.player.dim.y);
	init_img_xpm(&vars.field.img, vars.mlx, "./images/field.xpm", &vars.field.dim.x, &vars.field.dim.y);
	//ft_printf("EXIT x : %d	y : %d\nPLAYER x : %d	y : %d\n", vars.exit.pos.x, vars.exit.pos.y, vars.player.pos.x, vars.player.pos.y);
	//ft_printf("PLAYER WIDTH : %d\nPLAYER HEIGHT : %d\n", vars.player.dim.x, vars.player.dim.y);
	render_background(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop_hook(vars.mlx, &render, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, &keypress, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free(vars.img.img);
	//free(vars.img.addr);
	free_map(vars.map);
	return (0);
}

/*int	main(void)
{
	char **map;
	int	i;
	int	j;
	t_coord	player;

	i = 0;
	map = init_map("./maps/test2.ber");
	if (!map)
		return(1);
	while (map[i])
	{
		j = 0;
		while(map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				player = (t_coord){i, j};
				break;
			}
			j++;
		}
		i++;
	}
	ft_printf("Parsing : %d\n", parsing_map(player, map));
	return (0);
}*/
