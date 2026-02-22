/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:09:59 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:30:50 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *b)
{
	int		max;

	if (!b)
		return (-1);
	max = (b-> index);
	while (b)
	{
		if (max < (b-> index))
			max = b-> index;
		b = b-> next;
	}
	return (max);
}

void	push_chunks(t_stack **a, t_stack **b,
			int num_chunks, t_flag_op *flag_op)
{
	int		size;
	int		pushed;
	int		range;

	size = stack_size(*a);
	range = size / num_chunks;
	pushed = 0;
	if (range == 0)
		range = 1;
	while (*a)
	{
		if ((*a)->index <= pushed + range)
		{
			pb(a, b, flag_op);
			if ((*b)->index < pushed)
				rb(b, flag_op);
			pushed++;
		}
		else
			ra(a, flag_op);
	}
}

void	push_back(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	int		max_idx;
	int		pos;
	int		size;
	t_stack	*tmp;

	while (*b)
	{
		size = stack_size(*b);
		max_idx = get_max_index(*b);
		pos = 0;
		tmp = *b;
		while (tmp && tmp->index != max_idx && ++pos)
			tmp = tmp->next;
		if (pos <= size / 2)
		{
			while ((*b)->index != max_idx)
				rb(b, flag_op);
		}
		else
		{
			while ((*b)->index != max_idx)
				rrb(b, flag_op);
		}
		pa(a, b, flag_op);
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	int	size;
	int	num_chunks;

	size = stack_size(*a);
	if (size <= 100)
		num_chunks = 5;
	else
		num_chunks = 10;
	index_stack(a);
	push_chunks(a, b, num_chunks, flag_op);
	push_back(a, b, flag_op);
	if (*b)
		free_stack(b);
}
