/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:12:39 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:13:55 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_arr(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (a)
	{
		arr[i] = a-> value;
		a = a -> next;
		i++;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a-> value == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a-> next;
	}
}

void	index_stack(t_stack **a)
{
	int	size;
	int	*arr;

	size = stack_size(*a);
	arr = stack_to_arr(*a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	assign_index(*a, arr, size);
	free(arr);
}
