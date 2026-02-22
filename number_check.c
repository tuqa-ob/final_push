#include "push_swap.h"

int	ft_atol(const char *str, long *out)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = parse_sign(str, &i);
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			return (0);
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		return (0);
	*out = result * sign;
	return (1);
}

int	is_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a -> value == value)
			return (1);
		a = a -> next;
	}
	return (0);
}

int	parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	add_number(char *arg, t_stack **a)
{
	long	num;

	if (!ft_atol(arg, &num))
		return (0);
	if (is_duplicate(*a, (int)num))
		return (0);
	stack_add_back(a, (int)num);
	return (1);
}
