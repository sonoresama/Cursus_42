/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:09:24 by eorer             #+#    #+#             */
/*   Updated: 2023/02/21 17:52:13 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//	CAS OU dx - dy < 0

/*unsigned int	get_color(t_coord a, t_coord b, int pos, int d)
{
	int	red_a;
	int	red_b;
	int	red;
	unsigned int	color;

	red_a = (a.z / vars->max_high) * 256;
	red_b = (b.z / vars->max_high) * 256;
	ratio = red_b - red_a;
	red = red_a + (ratio * pos) / d;
	return (init_color(0, red, 256, 256));
}*/

int	valeur_absolue(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

t_coord	ft_sign(t_coord a, t_coord b)
{
	t_coord	sign;

	if (b.x > a.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (b.y > a.y)
		sign.y = 1;
	else
		sign.y = -1;
	sign.z = 0;
	return (sign);
}

void	draw_line_inf(t_vars *vars, t_coord a, t_coord b, unsigned int color)
{
	t_coord	d;
	t_coord	pos;
	t_coord	sign;
	int		error;
	int		slope;

	d.x = valeur_absolue(b.x - a.x);
	d.y = valeur_absolue(b.y - a.y);
	sign = ft_sign(a, b);
	pos = a;
	error = -d.y * sign.x;
	slope = 2 * d.x * sign.x;
	while (pos.y != b.y)
	{
		my_mlx_pixel_put(&vars->mlx_img, pos.x, pos.y, color);
		error += slope;
		if (sign.x * error >= 0)
		{
			pos.x += sign.x;
			error += -2 * d.y * sign.x;
		}
		pos.y += sign.y;
	}
}

//	CAS OU dx - dy > 0

void	draw_line_sup(t_vars *vars, t_coord a, t_coord b, unsigned int color)
{
	t_coord	d;
	t_coord	pos;
	t_coord	sign;
	int		error;
	int		slope;

	d.x = valeur_absolue(b.x - a.x);
	d.y = valeur_absolue(b.y - a.y);
	sign = ft_sign(a, b);
	pos = a;
	error = -d.x * sign.y;
	slope = 2 * d.y * sign.y;
	while (pos.x != b.x)
	{
		my_mlx_pixel_put(&vars->mlx_img, pos.x, pos.y, color);
		error += slope;
		if (sign.y * error >= 0)
		{
			pos.y += sign.y;
			error += -2 * d.x * sign.y;
		}
		pos.x += sign.x;
	}
}

void	draw_line(t_vars *vars, t_coord a, t_coord b, unsigned int color)
{
	t_coord	d;

	d.x = valeur_absolue(b.x - a.x);
	d.y = valeur_absolue(b.y - a.y);
	if (d.x > d.y)
		draw_line_sup(vars, a, b, color);
	else
		draw_line_inf(vars, a, b, color);
}
