/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:08:59 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:49:30 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_three_max(t_stack **a)
{
	t_stack	*u;
	t_stack	*d;
	t_stack	*t;

	u = *a;
	d = u->next;
	t = d->next;
	if (u->index > d->index && u->index > t->index)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (u->index < d->index && u->index < t->index)
	{
		ra(a, 1);
		if (u->index < d->index)
			sa(a, 1);
	}
	else
	{
		if (u->index > d->index && u->index < t->index)
			rra(a, 1);
		else
			sa(a, 1);
	}
}

void	arrange_three_min(t_stack **a)
{
	t_stack	*u;
	t_stack	*d;
	t_stack	*t;

	u = (*a);
	d = u->next;
	t = d->next;
	if (u->index < d->index && u->index < t->index)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (u->index > d->index && u->index > t->index)
	{
		ra(a, 1);
		if (u->index > d->index)
			sa(a, 1);
	}
	else
	{
		if (u->index < d->index && u->index > t->index)
			rra(a, 1);
		else
			sa(a, 1);
	}
}
