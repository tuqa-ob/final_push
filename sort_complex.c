/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:40:45 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 09:41:07 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_stack	*tmp;

	max = 0;
	bits = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	complex_sort(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, flag_op);
			else
				pb(a, b, flag_op);
			j++;
		}
		while (*b)
			pa(a, b, flag_op);
		i++;
	}
}
