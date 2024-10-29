/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:20:50 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:23:23 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	manage_args(t_stack **a, char **s, int i, int nb)
{
	t_stack	*tmp;
	t_stack	*new;

	nb = ft_atoi(s[i]);
	*a = ft_stnew(nb);
	while (++i && s[i])
	{
		tmp = *a;
		nb = ft_atoi(s[i]);
		while (tmp->next)
		{
			if (tmp->nbr == nb)
			{
				free_stack(&a);
				error_exit("Hay numeros repetidos");
			}
			tmp = tmp->next;
		}
		new = ft_stnew(nb);
		new->st = 0;
		tmp->next = new;
	}
}

void	create_stack(t_stack **a, int ac, char **av)
{
	char	**s;
	int		i;

	i = 1;
	s = av;
	if (ac == 2)
	{
		i = 0;
		s = ft_split(av[1], ' ');
	}
	manage_args(a, s, i, 0);
	if (ac == 2)
	{
		i = 0;
		while (s[i])
			i++;
		while (i--)
			free(s[i]);
		free(s);
	}
}

void	set_index(t_stack **one)
{
	int		max;
	t_stack	*a;
	t_stack	*last;

	max = get_length(*one);
	last = 0;
	while (max > 0)
	{
		a = *one;
		while (a)
		{
			if (!last || (a->nbr > last->nbr))
			{
				if (!(a->index))
					last = a;
			}
			a = a->next;
		}
		last->index = max;
		last = 0;
		max--;
	}
}

static	void	manage_top(t_stack **o, t_stack **b)
{
	t_stack	*t;

	t = *b;
	while (t)
	{
		if ((*o)->index < t->index && t->next)
		{
			if ((*o)->index > t->next->index)
				(*o)->top = t->next;
		}
		t = t->next;
	}
}

void	set_top(t_stack **a, t_stack **b)
{
	t_stack	*o;
	t_stack	*max;

	o = *a;
	max = ft_get_biggest(b);
	while (o)
	{
		o->top = 0;
		if (o->index > max->index)
			o->top = max;
		else if (o->index < ft_get_smallest(b)->index)
			o->top = max;
		else if (o->index < ft_st_last(*b)->index && o->index > (*b)->index)
			o->top = *b;
		else
			manage_top(&o, b);
		o = o->next;
	}
}
