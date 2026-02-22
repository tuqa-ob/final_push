/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:15:22 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:16:39 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_stack(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	tmp -> next = *dest;
	*dest = tmp;
	return (1);
}

void	pa(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	push_stack(a, b);
	write(1, "pa\n", 3);
	flag_op->op-> pa++;
	flag_op->op->ops++;
}

void	pb(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	push_stack(b, a);
	write(1, "pb\n", 3);
	flag_op->op->pb++;
	flag_op->op->ops++;
}
