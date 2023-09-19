/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:23:54 by emileorer         #+#    #+#             */
/*   Updated: 2023/09/13 10:56:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_print(t_philo *philo, char *str, int i_dead)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->lock);
	if (!data->dead)
	{
		if (!i_dead)
			printf("%ld %d %s\n", ft_get_time() - data->start, philo->id, str);
		else
		{
			printf("%ld %d %s\n", ft_get_time() - data->start, philo->id, str);
			data->dead = 1;
		}
	}
	pthread_mutex_unlock(&data->lock);
	return (0);
}

void	lock_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
		pthread_mutex_lock(&philo->fork);
	else
		pthread_mutex_lock(&philo->prev->fork);
	ft_print(philo, "has taken a fork", 0);
	if (philo->id % 2 == 1)
		pthread_mutex_lock(&philo->prev->fork);
	else
		pthread_mutex_lock(&philo->fork);
	ft_print(philo, "has taken a fork", 0);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->prev->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

void	sleep_eating(t_philo *philo)
{
	long	start_sleep;

	start_sleep = ft_get_time();
	ft_print(philo, "is eating", 0);
	while (1)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->lock);
		if (ft_get_time() - start_sleep >= philo->time_to_eat)
			break ;
		ft_usleep(1);
	}
}

int	ft_eating(t_philo *philo)
{
	lock_forks(philo);
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->eat);
	sleep_eating(philo);
	unlock_forks(philo);
	if (philo->nb_eat != -1)
		philo->nb_eat++;
	return (0);
}

void	ft_sleeping(t_philo *philo)
{
	long	start_sleep;

	start_sleep = ft_get_time();
	ft_print(philo, "is sleeping", 0);
	while (1)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->lock);
		if (ft_get_time() - start_sleep >= philo->time_to_sleep)
			break ;
		ft_usleep(1);
	}
}
