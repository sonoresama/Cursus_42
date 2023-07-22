/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:55:04 by eorer             #+#    #+#             */
/*   Updated: 2022/12/15 15:54:10 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"

typedef struct s_pile {
	int	*content;
	int	size;
}	t_pile;

t_pile	init_pile(char **arg, int size, t_long (*f)(const char *nptr));
void	print_piles(t_pile a, t_pile b, int size);
void	printf_array(int *arr, int size);
int		*sorted_tab(t_pile *a, int size);
int		is_sorted(int *tab, int size);

// FONCTIONS POUR LES INSCTRUCTIONS

void	rotate_a(t_pile *a, t_pile *b, int main);
void	rotate_b(t_pile *a, t_pile *b, int main);
void	rotate_rr(t_pile *a, t_pile *b);
void	reverse_rotate_a(t_pile *a, t_pile *b, int main);
void	reverse_rotate_b(t_pile *a, t_pile *b, int main);
void	reverse_rotate_rrr(t_pile *a, t_pile *b);
void	swap_a(t_pile *a, t_pile *b, int main);
void	swap_b(t_pile *a, t_pile *b, int main);
void	swap_ss(t_pile *a, t_pile *b);
void	push_a(t_pile *a, t_pile *b);
void	push_b(t_pile *a, t_pile *b);
void	quicksort(int *arr, int low, int high);

// ALGORITHMES DE TRI

void	insertion_sort(t_pile *a, t_pile *b);
void	three_digit_sort(t_pile *a, t_pile *b);
void	sort_five_digit(t_pile *a, t_pile *b);
void	sort_quick(t_pile *a, t_pile *b, int size);

#endif
