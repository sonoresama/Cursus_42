/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:19:22 by eorer             #+#    #+#             */
/*   Updated: 2023/09/19 18:27:26 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_normalize(t_vect *vector)
{
	float	norm;

	norm = sqrt(pow(vector->x, 2) + pow(vector->x, 2) + pow(vector->x, 2));
	if (!norm)
		return ;
	vector->x = vector->x / norm;
	vector->y = vector->y / norm;
	vector->z = vector->z / norm;
}
