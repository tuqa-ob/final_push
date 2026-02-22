/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:37:00 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 09:39:19 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	print_disorder(double dis)
{
	int		integer;
	int		decimal;

	integer = ((dis * 10000) / 100);
	decimal = ((int)(dis * 10000) % 100);
	ft_putstr_fd("disorder: ", 2);
	ft_putnbr(integer);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr(decimal);
	write(2, "%\n", 2);
}

void	print_strategy(t_stack *a, t_flag_op *flag_op)
{
	ft_putstr_fd("strategy: ", 2);
	if (flag_op->flag->mode == MODE_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (flag_op->flag-> mode == MODE_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (flag_op->flag-> mode == MODE_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)", 2);
	else
	{
		if (disorder(a) < 0.2)
			ft_putstr_fd("Adaptive / O(n^2)", 2);
		else if (disorder(a) < 0.5)
			ft_putstr_fd("Adaptive / O(n√n)", 2);
		else
			ft_putstr_fd("Adaptive / O(n log n)", 2);
	}
	write(2, "\n", 1);
}

void	print_total_ops(t_flag_op *fo)
{
	ft_putstr_fd("total_ops: ", 2);
	ft_putnbr(fo->op->ops);
	write(2, "\n", 1);
}
