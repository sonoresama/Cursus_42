/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:11:31 by eorer             #+#    #+#             */
/*   Updated: 2023/02/16 16:11:15 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 64
# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

// STRUCTURES //

typedef struct s_coord{
	int	y;
	int	x;
}	t_coord;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_case{
	t_coord	pos;
	t_coord	dim;
	t_img	img;
}	t_case;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	img;
	t_case	player;
	t_case	exit;
	t_case	border;
	t_case	field;
	t_case	item;
}	t_vars;

typedef int (*fp_move)(t_coord *pos, char **map);

// FONCTIONS //

int	recursive(t_coord *pos, char **map, fp_move *ft);
int	parsing_map(t_coord player, char **map);
int	number_rows(char *file_path);
void	init_img(t_img *img, void **mlx, int x, int y);
void	render_background(t_vars *vars);
void	render_background_rect(t_vars *vars);
void	render_mobile(t_vars *vars);
void	init_img_xpm(t_img *img, void *mlx, char *file_path, int *width, int *height);
//int	check_map(char **map);
int	init_game(t_vars *vars, char *map_path);
//void	free_map(char **map);
void	print_map(char **map);
int	draw_png(t_vars *vars, t_img *img, t_coord pos);
int	draw_rect(t_vars *vars, t_coord pos, unsigned int color);
char	**init_map(char *map_path);


unsigned int	mlx_get_pixel(t_img *img, int x, int y);
int	init_color(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
#endif
