/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:22:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/24 16:01:21 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo *ft_initiate_philo(char **argv)
{
	t_philo	*begin;
	t_philo *last;
	int		i;

	i = 1;
	begin = ft_lstnew(i, argv);
	while (++i <= ft_atoi(argv[1]))
		ft_lstadd_back(&begin, ft_lstnew(i, argv));
	last = ft_lstlast(begin);
	last->next = begin;
	begin->prev = last;
	return (begin);
}
