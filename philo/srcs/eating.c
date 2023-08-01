/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:23:54 by emileorer         #+#    #+#             */
/*   Updated: 2023/08/01 18:48:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_print(t_philo *philo, char *str)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->write);
	if (ft_get_time() - philo->last_meal >= philo->time_to_die)
	{
		pthread_mutex_lock(&data->lock);
		if (!data->dead)
			printf("%ld %d %s\n", ft_get_time() - data->start,
				philo->id, "died");
		data->dead = 1;
		pthread_mutex_unlock(&data->lock);
		return (1);
	}
	if (!data->dead)
		printf("%ld %d %s\n", ft_get_time() - data->start, philo->id, str);
	pthread_mutex_unlock(&data->write);
	return (0);
}

int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (ft_print(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(&philo->prev->fork);
	if (ft_print(philo, "has taken a fork"))
		return (1);
	philo->last_meal = ft_get_time();
	if (ft_print(philo, "is eating"))
		return (1);
	ft_usleep(philo->time_to_eat);
	if (philo->nb_eat != -1)
		philo->nb_eat++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->prev->fork);
	return (0);
}
