/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:55:18 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:43:05 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_stack *a, t_stack *b)
{
	int	n;

	if (b)
		return (0);
	n = a->nbr;
	while (a->next)
	{
		a = a->next;
		if (n > a->nbr)
			return (0);
		n = a->nbr;
	}
	return (1);
}
