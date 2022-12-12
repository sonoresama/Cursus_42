/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:54:26 by eorer             #+#    #+#             */
/*   Updated: 2022/12/12 15:13:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static	void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	printf_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%i ", arr[i]);
		i++;
	}
	printf("\n");
}

static	int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int *arr, int low, int high)
{
	int	sep;

	if (low < high)
	{
		sep = partition(arr, low, high);
		quicksort(arr, low, sep - 1);
		quicksort(arr, sep + 1, high);
	}
}

/*int	main()
{
	int	array[] = {4, 1, 7, 3, 6, 13, 2, 5, 11, 0, 7};
	int	size = sizeof(array)/sizeof(array[0]);

	printf_array(array, size);
	quicksort(array, 0, size - 1);
	printf_array(array, size);
	return(0);
}*/
