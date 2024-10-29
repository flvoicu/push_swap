/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:14:41 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:44:35 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, int st)
{
	if (st)
		pa(a, b, 1);
	else
		pb(b, a, 1);
}

void	nor_rot(t_stack **a, t_stack **b, int st)
{
	if (st)
		rb(b, 1);
	else
		ra(a, 1);
}

void	rev_rot(t_stack **a, t_stack **b, int st)
{
	if (st)
		rrb(b, 1);
	else
		rra(a, 1);
}

void	dou_rot(t_stack **a, t_stack **b, t_stack *n)
{
	if (n->up)
		rrr(a, b);
	else
		rr(a, b);
}

void	rotate(t_stack **a, t_stack **b, t_stack *n)
{
	t_stack	*tmp;

	if (n->top && (n->top->up == n->up) && n->off && n->top->off)
		dou_rot(a, b, n);
	else
	{
		if (n->off)
			tmp = n;
		else
			tmp = n->top;
		if (tmp->up)
			rev_rot(a, b, tmp->st);
		else
			nor_rot(a, b, tmp->st);
	}
}
