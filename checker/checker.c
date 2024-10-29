/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:19:43 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:09:13 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	compare(char *t, char *m)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (t[i] != m[i])
			return (0);
	}
	return (1);
}

static	void	move(t_stack **a, t_stack **b, char *t)
{
	if (compare(t, "sa\n"))
		sa(a, 0);
	if (compare(t, "sb\n"))
		sb(b, 0);
	if (compare(t, "ss\n"))
		ss(a, b);
	if (compare(t, "pa\n"))
		pa(a, b, 0);
	if (compare(t, "pb\n"))
		pb(b, a, 0);
	if (compare(t, "ra\n"))
		ra(a, 0);
	if (compare(t, "rb\n"))
		rb(b, 0);
	if (compare(t, "rr\n"))
		rr(a, b);
	if (compare(t, "rra\n"))
		rra(a, 0);
	if (compare(t, "rrb\n"))
		rrb(b, 0);
	if (compare(t, "rrr\n"))
		rrr(a, b);
}

static	void	check_t(t_stack **a, t_stack **b)
{
	char	*t;

	while (1)
	{
		t = get_next_line(0);
		if (!t)
			break ;
		move (a, b, t);
		free (t);
	}
	if (check(*a, *b))
		print_s("OK\n");
	else
		print_s("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (ac == 1)
		return(0);
	b = 0;
	create_stack(&a, ac, av);
	set_index(&a);
	check_t(&a, &b);
	free_stack(&a);
	free_stack(&b);
	exit (0);
}
