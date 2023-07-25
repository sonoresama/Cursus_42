/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:56:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/24 16:23:13 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philos(t_philo *philos);

void	free_all(t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	printf("nb de philo au moment de free : %i\n", philo->nb_philo);
	while(i < philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
		if (philo->prev)
			free(philo->prev);
		i++;
	}
	free(threads);
}

void	*ft_philo(void *arg)	
{
	t_philo *philo;
	int	i = 0;

	philo = (t_philo *)arg;
	while (i < 2)
	{
		ft_eating(philo);
		ft_print(philo, "is sleeping");
		usleep(philo->time_to_sleep);
		ft_print(philo, "is thinking");
		i++;
	}
	return (NULL);
}

int	ft_generate_threads(t_philo *philo, pthread_t *threads)
{
	int	i;
	int	nb_philo;

	i = 0;
	nb_philo = philo->nb_philo;
	printf("Nb de philos : %i\n", nb_philo );
	while (i < nb_philo)
	{
		philo->start = ft_get_time();
		if (pthread_create(&threads[i], NULL, &ft_philo, philo) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
//		pthread_join(threads[i], NULL);
		philo = philo->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
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
	//free_all(philos, threads);
	printf("sleeping : \n");
	usleep(philos->time_to_sleep * 1000);
	printf("done sleeping : \n");
	return (0);
}

void	print_philos(t_philo *philos)
{
	return;
	int	i;

	i = 0;
	while (philos && i++ < philos->nb_philo)
	{
		printf("Num philo : %i\n", philos->id);
		philos = philos->next;
	}
}
