/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:23:50 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:23:57 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adaptive(double d, t_stack **a, t_stack **b, t_flag_op *flag_op)
{
	if (d < 0.2)
		simple_sort(a, b, flag_op);
	else if (d < 0.5)
		medium_sort(a, b, flag_op);
	else
		complex_sort(a, b, flag_op);
}

void	run_algorithm(t_stack **a, t_flag_op *flag_op)
{
	t_stack	*b;
	double	d;

	if (!a || !*a)
		return ;
	b = NULL;
	index_stack(a);
	d = disorder(*a);
	if (flag_op->flag->mode == MODE_SIMPLE || stack_size(*a) <= 3)
		simple_sort(a, &b, flag_op);
	else if (flag_op->flag-> mode == MODE_MEDIUM)
		medium_sort(a, &b, flag_op);
	else if (flag_op->flag-> mode == MODE_COMPLEX)
		complex_sort(a, &b, flag_op);
	else
		adaptive(d, a, &b, flag_op);
	if (b)
		free_stack(&b);
}
