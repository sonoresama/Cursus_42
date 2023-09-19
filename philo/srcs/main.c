/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:56:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/09/18 17:16:24 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(char *arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_join_threads(t_philo *philos)
{
	int	i;
	int	nb;
	int	error;

	i = 0;
	nb = philos->nb_philo;
	while (i < nb)
	{
		error = pthread_join(philos->data->threads[i], NULL);
		if (error)
		{
			printf("Error waiting thread: %i\n", error);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("ERROR : Wrong number of arguments\n");
		return (1);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("ERROR : Negative or null numbers\n");
			return (1);
		}
		else if (check_args(argv[i]))
		{
			printf("ERROR : Wrong arguments\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;

	if (ft_check(argc, argv))
		return (0);
	philo = ft_initiate_philo(argv);
	if (!philo)
		return (1);
	philo->data->extra_think = 2*(philo->time_to_die - philo->time_to_eat
			- philo->time_to_sleep) / 3;
	if (philo->nb_philo == 1)
		return (one_philo(philo));
	else if (ft_generate_threads(philo))
		return (1);
	ft_exit(philo);
	return (0);
}
