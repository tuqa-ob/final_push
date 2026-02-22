/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:06:21 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:06:37 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ops(t_flag_op *flag_op)
{
	flag_op->op->ops = 0;
	flag_op->op->sa = 0;
	flag_op->op->sb = 0;
	flag_op->op->ss = 0;
	flag_op->op->pa = 0;
	flag_op->op->pb = 0;
	flag_op->op->ra = 0;
	flag_op->op->rb = 0;
	flag_op->op->rr = 0;
	flag_op->op->rra = 0;
	flag_op->op->rrb = 0;
	flag_op->op->rrr = 0;
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
