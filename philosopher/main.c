/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:17:08 by eorer             #+#    #+#             */
/*   Updated: 2023/04/13 17:48:41 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

typedef struct s_philo {
	int	nb;
	int	die;
	int	eat;
	int	sleep;
}	t_philo;

// 1000000 = 1sec

void	init_philo(t_philo *philo, char **argv)
{
	philo->nb = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]) * 1000;
	philo->eat = ft_atoi(argv[3]) * 1000;
	philo->sleep = ft_atoi(argv[4]) * 1000;
}

void	wait_threads(pthread_t *id, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->nb)
	{
		pthread_join(id[i], NULL);
		i++;
	}
}

void	*test(void *a)
{
	int	nb;

	nb = *(int *)a;
	printf("je suis le philo %i\n", nb);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo philo;
	pthread_t	*id;
	int	i;
	int	err;

	if (argc != 5)
	{
		printf("Bad argument number\n");
		return (1);
	}
	init_philo(&philo, argv);
	id = (pthread_t *)malloc(sizeof(pthread_t) * philo.nb);
	if (!id)
		return (1);
	i = 0;
	while (i < philo.nb)
	{
		err = pthread_create(&id[i], NULL, &test, &i);
		if (err)
		{
			free(id);
			perror("ERREUR : ");
			return (1);
		}
		i++;
	}
	wait_threads(id, &philo);
	return (0);
}
