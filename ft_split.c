/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:58:17 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/15 14:40:45 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count(char const *s, char c)
{
	int		count;
	char	*a;
	char	l;

	count = 0;
	a = (char *)s;
	l = c;
	while (*a)
	{
		if (*a == c && l != c)
			count++;
		l = *a;
		a++;
	}
	if (l != c)
		count++;
	return (count);
}

static int	check_s(char **a, int cnt)
{
	int	c;
	int	check;

	c = 0;
	check = 1;
	while (c < cnt && check)
	{
		if (a[c] == NULL)
			check = 0;
		c++;
	}
	if (!check)
	{
		c = 0;
		while (c < cnt)
		{
			if (a[c] != NULL)
				free(a[c]);
			c++;
		}
		free(a);
	}
	return (check);
}

static char	**create(char const *s, char c, int cnt, char **p)
{
	int		sz;
	int		len;
	char	l;

	sz = 0;
	len = ft_strlen((char *)s);
	l = c;
	p[cnt--] = NULL;
	while (len--)
	{
		if (l != c)
			sz++;
		if (s[len] == c && l != c)
		{
			p[cnt] = malloc((sz + 1) * sizeof(char));
			cnt--;
			sz = 0;
		}
		l = s[len];
	}
	if (l != c)
		p[cnt] = malloc((sz + 2) * sizeof(char));
	return (p);
}

static char	**populate(char **a, char const *s, char c, int cnt)
{
	int	i;
	int	j;
	int	d;

	i = 0;
	d = 0;
	while (i < cnt)
	{
		j = 0;
		while (s[d] && s[d] != c)
		{
			a[i][j] = s[d];
			d++;
			j++;
		}
		if (j)
		{
			a[i][j] = '\0';
			i++;
		}
		else
			d++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**a;

	cnt = count(s, c);
	if (cnt == 1)
		return (0);
	a = malloc((cnt + 1) * sizeof(char *));
	if (a == NULL)
		return (0);
	a = create(s, c, cnt, a);
	if (!check_s(a, cnt))
		return (0);
	return (populate(a, s, c, cnt));
}
