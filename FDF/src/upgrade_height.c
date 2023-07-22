/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:07:18 by eorer             #+#    #+#             */
/*   Updated: 2023/02/23 14:01:31 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	upgrade_height(t_vars *vars, int keycode)
{
	erase_img(vars);
	if (keycode == XK_w)
		vars->high /= 1.1;
	else if (keycode == XK_s)
		vars->high *= 1.1;
	vars->size_high = (float)vars->size / vars->high;
}

void	adjust_height(t_vars *vars)
{
	float	abs;

	abs = valeur_absolue(vars->max_high);
	while (abs > 10)
	{
		upgrade_height(vars, XK_s);
		abs /= 1.1;
	}
}
