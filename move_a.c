/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:11:43 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:42:50 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int pt)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (pt)
		print_s("sa\n");
}

void	pa(t_stack **a, t_stack **b, int pt)
{
	t_stack	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	(*a)->st = 0;
	if (pt)
		print_s("pa\n");
}

void	ra(t_stack **a, int pt)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = 0;
	last = ft_st_last(*a);
	last->next = tmp;
	if (pt)
		print_s("ra\n");
}

void	rra(t_stack **a, int pt)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	last = ft_st_last(*a);
	tmp = *a;
	last->next = tmp;
	*a = last;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	if (pt)
		print_s("rra\n");
}
