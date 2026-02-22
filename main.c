/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:06:53 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:12:23 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_flag		flag;
	t_op_info	op;
	t_flag_op	flag_op;
	double		dis;

	if (argc < 2)
		return (0);
	a = NULL;
	flag_op.flag = &flag;
	flag_op.op = &op;
	init_ops(&flag_op);
	init_flag(&flag);
	if (!parse_argv(argc, argv, &a, &flag_op))
	{
		free_stack(&a);
		return (1);
	}
	dis = disorder(a);
	if (a && !is_sorted(a))
		run_algorithm(&a, &flag_op);
	if (flag_op.flag->bench == 1)
		print_benchmark(&a, &flag_op, dis);
	free_stack(&a);
	return (0);
}
