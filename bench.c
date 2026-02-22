/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:40:11 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 09:40:23 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_benchmark(t_stack **a, t_flag_op *fo, double dis)
{
	write(2, "[bench] ", 8);
	print_disorder(dis);
	write(2, "[bench] ", 8);
	print_strategy(*a, fo);
	write(2, "[bench] ", 8);
	print_total_ops(fo);
	write(2, "[bench] ", 8);
	print_ops_counts(fo);
}
