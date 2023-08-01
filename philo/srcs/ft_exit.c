/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:26:10 by emileorer         #+#    #+#             */
/*   Updated: 2023/08/01 18:40:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philo(t_philo *philo)
{
	int			i;
	int			nb;
	t_philo	*tmp;

	i = 0;
	nb = philo->nb_philo;
	while (i < nb)
	{
		pthread_mutex_destroy(&philo->fork);
		tmp = philo;
		if (philo->next)
			philo = philo->next;
		if (tmp)
			free(tmp);
		i++;
	}
}
	
void	ft_exit(t_philo *philo)
{
	t_data	*data;

	exit(0);
	data = philo->data;
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	free(data->threads);
	free(data);
	free_philo(philo);
	exit(0);
}
