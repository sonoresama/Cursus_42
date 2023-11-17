/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:34:09 by eorer             #+#    #+#             */
/*   Updated: 2023/10/13 19:47:20 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define SIZE 32
# define W_WIDTH 2500
# define W_HEIGHT 1400
# define SPEED_MOVE 10
# define ZOOM 4

// STRUCTURES //

typedef unsigned int	t_ui;

typedef struct s_coord{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	float	high;
	float	size_high;
	float	angel;
	t_coord	start;
	t_coord	w_center;
	t_coord	m_center;
	t_img	mlx_img;
	int		**map;
	int		**colors;
	int		w_width;
	int		w_height;
	int		length_map;
	int		height_map;
	int		max_high;
	int		size;
}	t_vars;

// FONCTIONS //

char	**init_map(char *map_path);
void	draw_line(t_vars *vars, t_coord a, t_coord b, unsigned int color);
void	draw_grid(t_vars *vars, int **map, int len, unsigned int color);
void	draw_mid(t_vars *vars);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_img(t_img *img, void **mlx, int x, int y);
void	free_map(char **map);
void	print_map(char **map);
void	print_tab(int **tab, int length);
void	free_tab(int **tab);
void	center_map(t_vars *vars);
void	center_y(t_vars *vars);
void	center_x(t_vars *vars);
void	zoom_plus(t_vars *vars);
void	zoom_moins(t_vars *vars);
void	adjust_height(t_vars *vars);
t_coord	coord_to_plan(int x, int y, int z, t_vars *vars);

int		init_mlx(t_vars *vars);
int		init_color(int t, int r, int g, int b);
int		init_values(t_vars *vars, char *file_path);
int		**get_map(char *file_path, int *length_map);
int		check_arg(int argc, char *str);
int		number_row_file(char *file_path);
int		number_cols(char **map);
int		number_row_map(char **map);
int		valeur_absolue(int nb);

t_ui	mlx_get_pixel(t_img *img, int x, int y);

// BONUS

void	upgrade_height(t_vars *vars, int keycode);
void	manage_event(t_vars *vars, int keycode);
void	erase_img(t_vars *vars);
void	move_map(t_vars *vars, int keycode);
void	zoom(t_vars *vars, int keycode);

#endif
