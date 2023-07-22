/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:22:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/22 16:33:19 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *ft_initiate_philo(char **argv)
{
	t_philo	*begin;
	int		i;

	i = 1;
	begin = ft_lstnew(i, argv);
	printf("Nb de philos : %i\n", ft_atoi(argv[1]));
	while (++i <= ft_atoi(argv[1]))
		ft_lstadd_back(&begin, ft_lstnew(i, argv));
	return (begin);
}
