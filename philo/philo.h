/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:57:04 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/24 16:07:38 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

// STRUCTURES //

typedef struct s_data {
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long			start;
}					t_data;

typedef struct s_philo {
	int				id;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				last_meal;
	int				start;
	pthread_mutex_t fork;
	struct s_philo			*prev;
	struct s_philo			*next;
}					t_philo;

// FONCTIONS //

t_philo *ft_initiate_philo(char **argv);
long	ft_get_time(void);
void	ft_print(t_philo *philo, char *str);
void	ft_eating(t_philo *philo);

//  UTILITIES  //

int	ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstlast(t_philo *lst);
t_philo	*ft_lstnew(int id, char **args);

#endif
