/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:01:59 by eorer             #+#    #+#             */
/*   Updated: 2023/07/26 00:50:38 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	lancement_threads(pthread_t *threads, t_philo *philo, int i);

void	*ft_philo(void *arg)
{
	t_philo *philo;
	int	i = 0;

	philo = (t_philo *)arg;
	while (i++ < 10000)
	{
		if (ft_eating(philo))
			exit (0);
		ft_print(philo, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
		if (ft_print(philo, "is thinking"))
			exit(0);
	}
	return (NULL);
}

int	ft_generate_threads(t_philo *philo)
{
	int		i;

	i = 0;
	philo->data->start = ft_get_time();
	if (lancement_threads(philo->data->threads, philo, 0))
		return (1);
	if (lancement_threads(philo->data->threads, philo->next, 1))
		return (1);
	return (0);
}

int	lancement_threads(pthread_t *threads, t_philo *philo, int i)
{
	while (i < philo->nb_philo)
	{
		philo->last_meal = ft_get_time(); //philo->data->start;
		if (pthread_create(&threads[i], NULL, &ft_philo, philo) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		philo = philo->next->next;
		i += 2;
	}
	return (0);
}

