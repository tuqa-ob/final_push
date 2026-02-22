/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:48:57 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 09:49:06 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_flag(t_flag *flag)
{
	flag -> mode = MODE_DEFAULT;
	flag -> bench = 0;
}

static int	set_strategy(t_flag_op *flag_op, t_mode mode)
{
	if (flag_op->flag-> mode != MODE_DEFAULT)
		return (-1);
	flag_op->flag-> mode = mode;
	return (1);
}

int	handle_flag(char *arg, t_flag_op *flag_op)
{
	if (arg[0] != '-' && arg[1])
		return (0);
	if (arg[1] >= '0' && arg[1] <= '9')
		return (0);
	if (!ft_strcmp(arg, "--simple"))
		return (set_strategy(flag_op, MODE_SIMPLE));
	else if (!ft_strcmp(arg, "--medium"))
		return (set_strategy(flag_op, MODE_MEDIUM));
	else if (!ft_strcmp(arg, "--complex"))
		return (set_strategy(flag_op, MODE_COMPLEX));
	else if (!ft_strcmp(arg, "--adaptive"))
		return (set_strategy(flag_op, MODE_ADAPTIVE));
	else if (!ft_strcmp(arg, "--bench"))
	{
		flag_op->flag-> bench = 1;
		return (1);
	}
	return (0);
}
