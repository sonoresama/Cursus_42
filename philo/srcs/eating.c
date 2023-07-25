/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:23:54 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/24 16:18:25 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", ft_get_time() - philo->start, philo->id, str);
}

long	ft_get_time(void)
{
	struct timeval	current_time;
	int time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->prev->fork);
	ft_print(philo, "has taken a fork");
	philo->last_meal = ft_get_time();
	ft_print(philo, "is eating");
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->prev->fork);
	if (philo->nb_eat != -1)
		philo->nb_eat++;
}

