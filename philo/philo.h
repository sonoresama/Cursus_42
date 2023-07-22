/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:57:04 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/22 16:30:24 by emileorer        ###   ########.fr       */
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

typedef struct s_philo {
	int				id;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t fork;
	struct s_philo			*prev;
	struct s_philo			*next;
}					t_philo;

// FONCTIONS //

t_philo *ft_initiate_philo(char **argv);

//  UTILITIES  //

int	ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstlast(t_philo *lst);
t_philo	*ft_lstnew(int id, char **args);

#endif
