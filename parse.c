/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:14:15 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:14:24 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **a, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new -> value = value;
	new -> index = -1;
	new -> next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	tmp = *a;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

int	parse_argv(int argc, char **argv, t_stack **a, t_flag_op *flag_op)
{
	int		i;
	int		ret;

	i = 1;
	while (i < argc)
	{
		ret = handle_flag(argv[i], flag_op);
		if (ret == -1)
		{
			error();
			return (0);
		}
		if (ret == 1)
		{
			i++;
			continue ;
		}
		if (ret == 0 && !add_number(argv[i], a))
			return (error(), 0);
		i++;
	}
	return (1);
}
