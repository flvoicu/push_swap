/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:53:03 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:10:21 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_a(t_stack **a, t_stack **b)
{
	t_stack	*t;
	t_stack	*max;

	while (get_length(*a) > 3)
	{
		set_top(a, b);
		set_off(a, b, 1);
		set_moves(a);
		t = get_node(a);
		move(a, b, t);
	}
	if (get_length(*a) == 3 && check(*a, 0) == 0)
		arrange_three_min(a);
	max = ft_get_biggest(b);
	while (ft_st_last(*a)->index > max->index)
		rra(a, 1);
}

void	manage_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b, 1);
		if ((*a)->index - 1 == ft_st_last(*a)->index)
			rra(a, 1);
	}
}

void	manage_stack(t_stack **a, t_stack **b)
{
	t_stack	*n;

	manage_a(a, b);
	manage_b(a, b);
	set_off(a, b, 0);
	n = ft_get_smallest(a);
	while (*a != n)
		rotate(a, b, n);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (ac == 1)
		error_exit("Pocos argumentos");
	b = 0;
	i = 2;
	create_stack(&a, ac, av);
	if (check(a, b) == 0)
	{
		set_index(&a);
		while (--i && get_length(a) > 3)
			pb(&b, &a, 1);
		manage_stack(&a, &b);
	}
	free_stack(&a);
	exit (0);
}
