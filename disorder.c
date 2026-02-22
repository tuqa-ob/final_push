/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:45:22 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 09:46:59 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	long	pairs;
	long	mistakes;

	pairs = 0;
	mistakes = 0;
	i = a;
	while (i)
	{
		j = i -> next;
		while (j)
		{
			pairs++;
			if (i -> value > j -> value)
				mistakes++;
			j = j -> next;
		}
		i = i -> next;
	}
	if (pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)pairs);
}
