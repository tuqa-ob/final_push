/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaidat <tobaidat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:21:21 by tobaidat          #+#    #+#             */
/*   Updated: 2026/02/17 10:51:04 by tobaidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_op_info
{
	long	ops;
	long	sa;
	long	sb;
	long	ss;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
	long	pa;
	long	pb;
}	t_op_info;

typedef enum e_mode
{
	MODE_DEFAULT,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX,
	MODE_ADAPTIVE
}	t_mode;

typedef struct s_flag
{
	t_mode	mode;
	int		bench;
}	t_flag;

typedef struct s_flag_op
{
	t_flag		*flag;
	t_op_info	*op;
}	t_flag_op;

void	print_benchmark(t_stack **a, t_flag_op *flag_op, double dis);
void	print_disorder(double dis);
void	print_strategy(t_stack *a, t_flag_op *fo);
void	print_total_ops(t_flag_op *fo);
void	print_ops_counts(t_flag_op *fo);
double	disorder(t_stack *a);
void	init_ops(t_flag_op *flag_op);
void	error(void);
void	free_stack(t_stack **stack);
void	init_flag(t_flag *flag);
int		handle_flag(char *arg, t_flag_op *flag_op);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	ft_putnbr(long n);
void	ft_putstr_fd(char *s, int fd);
int		main(int argc, char **argv);
void	pa(t_stack **a, t_stack **b, t_flag_op *flag_op);
void	pb(t_stack **a, t_stack **b, t_flag_op *flag_op);
void	ra(t_stack **a, t_flag_op *flag_op);
void	rb(t_stack **b, t_flag_op *flag_op);
void	rr(t_stack **a, t_stack **b, t_flag_op *flag_op);
void	rra(t_stack **a, t_flag_op *flag_op);
void	rrb(t_stack **b, t_flag_op *flag_op);
void	rrr(t_stack **a, t_stack **b, t_flag_op *flag_op);
void	sa(t_stack **a, t_flag_op *flag_op);
void	sb(t_stack **b, t_flag_op *flag_op);
void	ss(t_stack **a, t_stack **b, t_flag_op *flag_op);
int		ft_atol(const char *str, long *out);
int		is_duplicate(t_stack *a, int value);
void	stack_add_back(t_stack **a, int value);
int		parse_sign(const char *str, int *i);
int		parse_argv(int argc, char **argv, t_stack **a, t_flag_op *flag_op);
void	run_algorithm(t_stack **a, t_flag_op *flag_op);
int		get_max_bits(t_stack *a);
void	complex_sort(t_stack **a, t_stack **b, t_flag_op *flag_op);
int		get_chunk_size(int stack_size);
int		get_max_index(t_stack *b);
void	push_chunks(t_stack **a, t_stack **b,
			int num_chunks, t_flag_op *flag_op);
void	push_back(t_stack **a, t_stack **b, t_flag_op *flag_op);
void	medium_sort(t_stack **a, t_stack **b, t_flag_op *flag_op);
int		*stack_to_arr(t_stack *a, int size);
void	sort_array(int *arr, int size);
void	assign_index(t_stack *a, int *arr, int size);
void	index_stack(t_stack **a);
int		find_min_index(t_stack *a);
int		stack_size(t_stack *stack);
void	move_min_to_top(t_stack **a, t_flag_op *flag_op);
void	sort_three(t_stack **a, t_flag_op *flag_op);
void	simple_sort(t_stack **a, t_stack **b, t_flag_op *flag_op);
int		add_number(char *arg, t_stack **a);
#endif
