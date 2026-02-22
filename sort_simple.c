/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:24:47 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:24:54 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *a)
{
	int	min;
	int	index;
	int	i;

	min = a->value;
	index = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			index = i;
		}
		a = a->next;
		i++;
	}
	return (index);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	move_min_to_top(t_stack **a, t_flag_op *flag_op)
{
	int	index;
	int	size;

	index = find_min_index(*a);
	size = stack_size(*a);
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(a, flag_op);
	}
	else
	{
		while (index++ < size)
			rra(a, flag_op);
	}
}

void	sort_three(t_stack **a, t_flag_op *flag_op)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, flag_op);
	else if (first > second && second > third)
	{
		ra(a, flag_op);
		sa(a, flag_op);
	}
	else if (first > second && second < third && first > third)
		ra(a, flag_op);
	else if (first < second && second > third && first < third)
	{
		sa(a, flag_op);
		ra(a, flag_op);
	}
	else if (first < second && second > third && first > third)
		rra(a, flag_op);
}

void	simple_sort(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, flag_op);
	}
	else if (size == 3)
		sort_three(a, flag_op);
	else if (size > 3)
	{
		while (stack_size(*a) > 3)
		{
			move_min_to_top(a, flag_op);
			pb(a, b, flag_op);
		}
		sort_three(a, flag_op);
		while (*b)
			pa(a, b, flag_op);
	}
}
