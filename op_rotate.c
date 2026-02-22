/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:22:27 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:22:31 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return (0);
	first = *s;
	*s = first -> next;
	first -> next = NULL;
	last = *s;
	while (last -> next)
		last = last -> next;
	last -> next = first;
	return (1);
}

void	ra(t_stack **a, t_flag_op *flag_op)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
	flag_op->op->ra++;
	flag_op->op->ops++;
}

void	rb(t_stack **b, t_flag_op *flag_op)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
	flag_op->op->rb++;
	flag_op->op->ops++;
}

void	rr(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
	flag_op->op->rr++;
	flag_op->op->ops++;
}
