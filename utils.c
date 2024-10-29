/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:01:11 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:10:36 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_s(char *a)
{
	write(1, a, ft_strlen(a));
}

void	error_exit(char *s)
{
	print_s(s);
	exit (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*t;

	while (*a)
	{
		t = *a;
		*a = (*a)->next;
		free(t);
	}
	free (*a);
}
