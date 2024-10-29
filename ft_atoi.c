/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:28:21 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:00:16 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	neg;
	int	val;

	neg = 1;
	val = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + *str - '0';
		str++;
	}
	if (*str != '\0' && *str != ' ')
		error_exit("Hay numeros invalidos");
	val *= neg;
	return (val);
}
