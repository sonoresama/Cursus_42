/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:54:38 by eorer             #+#    #+#             */
/*   Updated: 2022/12/07 18:48:01 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_num(char **arg, int size, int (*f)(const char *nptr))
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = f(arg[i + 1]);
		i++;
	}
	return (array);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	i;

	array = convert_to_num(argv, argc - 1, &ft_atoi);
	if (!array)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("--> %i\n", array[i]);
		i++;
	}
	free (array);
	return (0);
}
