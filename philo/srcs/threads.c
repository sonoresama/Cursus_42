/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:01:59 by eorer             #+#    #+#             */
/*   Updated: 2023/09/18 17:30:20 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_nb_eat(t_philo *philo);
int	lancement_threads(pthread_t *threads, t_philo *philo, int i);

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		ft_eating(philo);
		ft_sleeping(philo);
	//	ft_print(philo, "is sleeping", 0);
	//	ft_usleep(philo->time_to_sleep);
		ft_print(philo, "is thinking", 0);
		if (philo->data->extra_think > 0)
			usleep(philo->data->extra_think);
		pthread_mutex_lock(&(philo->data->lock));
		if (check_nb_eat(philo))
			philo->data->finished++;
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&(philo->data->lock));
			return (NULL);
		}
		pthread_mutex_unlock(&(philo->data->lock));
	}
}

void	*checker(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->eat);
		if (ft_get_time() - philo->last_meal >= philo->time_to_die)
			ft_print(philo, "died", 1);
		pthread_mutex_unlock(&philo->eat);
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->finished >= philo->nb_philo)
			philo->data->dead = 1;
		if (philo->data->dead == 1)
		{
			pthread_mutex_unlock(&philo->data->lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->lock);
		philo = philo->next;
		if (philo->time_to_eat == philo->time_to_sleep)
			usleep(100);
		else
			usleep(1000);
	}
	return (NULL);
}

int	ft_generate_threads(t_philo *philo)
{
	philo->data->start = ft_get_time();
	if (lancement_threads(philo->data->threads, philo, 0))
		return (1);
	usleep(10);
	if (lancement_threads(philo->data->threads, philo->next, 1))
		return (1);
	usleep(10);
	checker(philo);
	ft_join_threads(philo);
	return (0);
}

int	lancement_threads(pthread_t *threads, t_philo *philo, int i)
{
	while (i < philo->nb_philo)
	{
		philo->last_meal = ft_get_time();
		if (pthread_create(&threads[i], NULL, &ft_philo, philo) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		philo = philo->next->next;
		i += 2;
		usleep(1);
	}
	return (0);
}

int	check_nb_eat(t_philo *philo)
{
	if (philo->nb_eat == philo->data->max_meal)
		return (1);
	return (0);
}
