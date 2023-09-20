/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:32:23 by eorer             #+#    #+#             */
/*   Updated: 2023/09/20 16:43:33 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_vect	add_vectors(t_vect vect_a, t_vect vect_b)
{
	t_vect	result;

	result.x = vect_a.x + vect_b.x;
	result.y = vect_a.y + vect_b.y;
	result.z = vect_a.z + vect_b.z;
	return (result);
}

t_vect	sous_vectors(t_vect vect_a, t_vect vect_b)
{
	t_vect	result;

	result.x = vect_a.x - vect_b.x;
	result.y = vect_a.y - vect_b.y;
	result.z = vect_a.z - vect_b.z;
	return (result);
}

t_vect	mult_const_vector(t_vect vector, double c)
{
	return ((t_vect){c * vector.x, c * vector.y, c * vector.z});
}

double	mult_vectors(t_vect vect_a, t_vect vect_b)
{
	double	result;

	result = vect_a.x * vect_b.x + vect_a.y * vect_b.y + vect_a.z * vect_b.z; 
	return (result);
}

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
