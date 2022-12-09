/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:55:04 by eorer             #+#    #+#             */
/*   Updated: 2022/12/09 16:02:47 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ftprintf/ft_printf.h"

typedef struct s_pile {
	
	int	*content;
	int	size;
}	pile;

pile	init_pile(char **arg, int size, int (*f)(const char *nptr));
void	rotate(pile a);
void	reverse_rotate(pile a);
void	swap(pile a);
void	push(pile a, pile b);

#endif
