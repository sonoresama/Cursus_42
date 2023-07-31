/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:26:10 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/28 16:39:54 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philo(t_philo *philo)
{
	int			i;
	t_philo	*tmp;

	i = -1;
	while (++i < philo->nb_philo)
	{
		tmp = philo;
		pthread_mutex_destroy(&philo->fork);
		if (philo->next)
			philo = philo->next;
		free(tmp);
	}
}
	
void	ft_exit(t_philo *philo)
{
	t_data	*data;

	exit(0);
	data = philo->data;
	free_philo(philo);
	free(data->threads);
//	ft_join_threads(philo);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	free(data);
	exit(0);
}
