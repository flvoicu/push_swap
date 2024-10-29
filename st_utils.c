/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:51:43 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:44:19 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stnew(int i)
{
	t_stack	*t;

	t = malloc(sizeof(t_stack));
	if (t == NULL)
		return (NULL);
	t->nbr = i;
	t->index = 0;
	t->next = NULL;
	return (t);
}

t_stack	*ft_get_biggest(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*big;

	tmp = *a;
	big = *a;
	while (tmp)
	{
		if (tmp->index > big->index)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_stack	*ft_get_smallest(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*big;

	tmp = *a;
	big = *a;
	while (tmp)
	{
		if (tmp->index < big->index)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_stack	*ft_st_last(t_stack *st)
{
	if (!st)
		return (0);
	while (st->next)
		st = st->next;
	return (st);
}

int	get_length(t_stack *a)
{
	int	cnt;

	cnt = 0;
	while (a)
	{
		cnt++;
		a = a->next;
	}
	return (cnt);
}
