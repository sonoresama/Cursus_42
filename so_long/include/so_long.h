/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:32:50 by eorer             #+#    #+#             */
/*   Updated: 2023/02/09 11:26:32 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define FILE_PATH "./basic_map.ber"
# define SIZE_SQR 64

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coord{
	int	y;
	int	x;
}	t_coord;

typedef struct s_case{
	t_coord	pos;
	t_img	*img;
}	t_case;

/*typedef struct s_case{
	int	y;
	int	x;
	char	value;
}	t_case;*/

typedef struct s_rect{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	char	**map;
	t_img	*item;
	t_img	*border;
	t_img	*field;
	t_case	player;
	t_case	exit;
	t_img	img;
}	t_vars;


// PROTOTYPES

void	init_img_xpm(t_vars *vars, t_img *img, char *file_path);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_img(t_img *img, void **mlx, int x, int y);
int	init_game(t_vars *vars, int *len_line);
void	move_player(int key, t_vars *vars);
void	print_map(t_vars *vars);
int		init_color(int t, int r, int g, int b);
int		draw_rect(t_vars *vars, t_coord pos, char value);
int		number_row(char *file_path);
int		put_map_on_img(t_vars *vars);
char		**init_map(int *len_line);

#endif
