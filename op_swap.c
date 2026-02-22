/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:25:14 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:25:55 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*second;

	if (!s || !*s || !(*s)->next)
		return (0);
	tmp = *s;
	second = tmp->next;
	tmp->next = second->next;
	second->next = tmp;
	*s = second;
	return (1);
}

void	sa(t_stack **a, t_flag_op *flag_op)
{
	swap_stack(a);
	write(1, "sa\n", 3);
	flag_op->op->sa++;
	flag_op->op->ops++;
}

void	sb(t_stack **b, t_flag_op *flag_op)
{
	swap_stack(b);
	write(1, "sb\n", 3);
	flag_op->op->sb++;
	flag_op->op->ops++;
}

void	ss(t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
	flag_op->op->ss++;
	flag_op->op->ops++;
}
