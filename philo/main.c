/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:56:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/22 16:37:01 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(t_philo *philo)
{
	printf("je suis le philosophe %i\n", philo->id);
	return (NULL);
}

int	ft_generate_threads(t_philo *philo, pthread_t *threads)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = philo->nb_philo;
	while (i < nb_philo)
	{
		if (pthread_create(&threads[i], NULL, ft_philo(philo), NULL) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		philo = philo->next;
		i++;
	}
	return (0);
}

void	print_philos(t_philo *philos)
{
	return ;
	while (philos)
	{
		printf("Num philo : %i\n", philos->id);
		philos = philos->next;
	}
}

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_philo	*philos;

	if (argc != 5)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!threads)
	{
		printf("Error allocating memory\n");
		return (1);
	}
	philos = ft_initiate_philo(argv);
	print_philos(philos);
	ft_generate_threads(philos, threads);
	return (0);
}
