/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:54:26 by eorer             #+#    #+#             */
/*   Updated: 2022/12/09 17:59:15 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_swap(int *a, int *b)
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

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            ft_swap(&arr[i], &arr[j]);
        }
    }
    ft_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int	separation(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	pos;

	pivot = arr[high];
	i = low - 1;
	while (i++ < high)
	{
		if (arr[i] > pivot)
		{
			j = i;
			while (j < high)
			{
				j++;
				if (arr[j] <= pivot)
				{
					ft_swap(&arr[j], &arr[i]);
					pos = i;
					break ;
				}
			}
		}
	}
	return (pos);
}

void	quicksort(int *arr, int low, int high)
{
	int	sep;

	if (low < high)
	{
		sep = separation(arr, low, high);
		quicksort(arr, low, sep - 1);
		quicksort(arr, sep + 1, high);
	}
}

int	main()
{
	int	array[] = {4, 1, 7, 3, 6, 8, 2, 5};
	int	size = sizeof(array)/sizeof(array[0]);

	printf_array(array, size);
	quicksort(array, 0, size - 1);
	printf_array(array, size);
	return(0);
}
