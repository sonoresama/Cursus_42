/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:15:39 by emileorer         #+#    #+#             */
/*   Updated: 2023/08/01 18:49:32 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_print(philo, "has taken a fork");
	ft_usleep(philo->time_to_die);
	ft_print(philo, "died");
	return (NULL);
}

int	one_philo(t_philo *philo)
{
	pthread_t	thread;

	philo->data->start = ft_get_time();
	philo->last_meal = philo->data->start;
	if (pthread_create(&thread, NULL, &ft_one_philo, philo) != 0)
	{
		printf("Error creating thread\n");
		return (1);
	}
	pthread_join(thread, NULL);
	//free
	return (0);
}
