/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:22:53 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:23:36 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack **s)
{
	t_stack	*prev;
	t_stack	*last;

	if (!s || !*s || !(*s)-> next)
		return (0);
	last = *s;
	while (last -> next)
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	last -> next = *s;
	*s = last;
	return (1);
}

void	rra(t_stack **a, t_flag_op *flag_op)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
	flag_op->op -> rra++;
	flag_op->op->ops++;
}

void	rrb(t_stack **b, t_flag_op *flag_op)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
	flag_op->op->rrb++;
	flag_op->op->ops++;
}

void	rrr(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
	flag_op->op->rrr++;
	flag_op->op->ops++;
}
