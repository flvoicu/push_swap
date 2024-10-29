/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:57:04 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:17:03 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **a, t_stack **b, t_stack *n)
{
	while (*a != n && *b != n->top)
		rotate(a, b, n);
	set_off(a, b, 1);
	while (*a != n || *b != n->top)
		rotate(a, b, n);
	push(a, b, n->st);
}

t_stack	*get_node(t_stack **a)
{
	t_stack	*t;
	t_stack	*m;

	t = *a;
	m = *a;
	while (t)
	{
		if (t->moves < m->moves)
			m = t;
		t = t->next;
	}
	return (m);
}

void	set_off(t_stack **a, t_stack **b, int n)
{
	int		i;
	t_stack	*node;
	t_stack	*tmp;

	node = *a;
	while (node)
	{
		i = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp == node)
			{
				node->off = i;
				check_node(&node, *a);
				tmp = NULL;
			}
			else
				tmp = tmp->next;
			i++;
		}
		node = node->next;
	}
	if (n)
		set_off(b, a, 0);
}

void	check_node(t_stack **node, t_stack *a)
{
	int	i;
	int	len;

	len = get_length(a);
	i = (*node)->off;
	(*node)->up = 0;
	if (i > (len / 2))
	{
		(*node)->off = len - i;
		(*node)->up = 1;
	}
}

void	set_moves(t_stack **a)
{
	t_stack	*one;

	one = *a;
	while (one)
	{
		one->moves = one->off;
		if (one->top)
		{
			if (one->up == one->top->up)
			{
				if (one->off > one->top->off)
					one->moves = one->off;
				else
					one->moves = one->top->off;
			}
			else
				one->moves = one->top->off + one->off;
		}
		one = one->next;
	}
}
