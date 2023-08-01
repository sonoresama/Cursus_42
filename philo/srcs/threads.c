/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:01:59 by eorer             #+#    #+#             */
/*   Updated: 2023/08/01 18:45:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_nb_eat(t_philo *philo);
int	lancement_threads(pthread_t *threads, t_philo *philo, int i);

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->data->dead == 0)
	{
		if (ft_eating(philo))
			ft_exit (philo);
		ft_print(philo, "is sleeping");
		ft_usleep(philo->time_to_sleep);
		if (ft_print(philo, "is thinking"))
			ft_exit(philo);
		if (check_nb_eat(philo))
		{
			pthread_mutex_lock(&(philo->data->lock));
			philo->data->finished ++;
			pthread_mutex_unlock(&(philo->data->lock));
		}
	}
	return (NULL);
}

void	*checker(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->dead == 0)
	{
		pthread_mutex_lock(&data->lock);
		if (data->finished >= data->max_meal)
			data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	return (NULL);
}

int	ft_generate_threads(t_philo *philo)
{
//	pthread_t	t_checker;

//	if (philo->data->max_meal != 0)
//	{
//		if (pthread_create(&t_checker, NULL, &checker, philo->data) != 0)
//		{
//			printf("Error creating thread\n");
//			return (1);
//		}
//	}
	checker(philo);
	philo->data->start = ft_get_time();
	if (lancement_threads(philo->data->threads, philo, 0))
		return (1);
	usleep(10);
	if (lancement_threads(philo->data->threads, philo->next, 1))
		return (1);
	ft_join_threads(philo);
	return (0);
}

int	lancement_threads(pthread_t *threads, t_philo *philo, int i)
{
	while (i < philo->nb_philo)
	{
		philo->last_meal = philo->data->start;
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
	if (philo->data->max_meal == 0)
		return (0);
	if (philo->nb_eat < philo->data->max_meal)
		return (0);
	return (1);
}
