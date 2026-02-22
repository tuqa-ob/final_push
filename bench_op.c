/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:39:36 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 09:39:57 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ops_part1(t_flag_op *fo)
{
	if (!fo || !fo->flag || !fo->flag->bench)
		return ;
	ft_putstr_fd("sa: ", 2);
	ft_putnbr(fo->op->sa);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr(fo->op->sb);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr(fo->op->ss);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr(fo->op->pa);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr(fo->op->pb);
	ft_putstr_fd("\n", 2);
}

static void	print_ops_part2(t_flag_op *fo)
{
	if (!fo || !fo->flag || !fo->flag->bench)
		return ;
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr(fo->op->ra);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr(fo->op->rb);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr(fo->op->rr);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr(fo->op->rra);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr(fo->op->rrb);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr(fo->op->rrr);
	ft_putstr_fd("\n", 2);
}

void	print_ops_counts(t_flag_op *fo)
{
	print_ops_part1(fo);
	print_ops_part2(fo);
}
