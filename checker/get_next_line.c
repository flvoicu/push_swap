/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:15:19 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/08 21:47:19 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (dst == NULL && src == NULL)
		return (0);
	s = (char *) src;
	d = (char *) dst;
	if (s < d && s + len > d)
	{
		s = s + len;
		d = d + len;
		while (len--)
			*(--d) = *(--s);
	}
	else
		while (len--)
			*d++ = *s++;
	*d = '\0';
	return (dst);
}

static char	*create(char *buff, char *tmp, int cnt)
{
	int		c;
	int		i;
	char	*p;

	c = 0;
	i = 0;
	p = malloc((ft_strlen(tmp) + cnt + 1) * sizeof(char));
	if (!p)
		return (0);
	while (tmp[c])
	{
		p[c] = tmp[c];
		c++;
	}
	free (tmp);
	while (cnt--)
	{
		p[c] = buff[i];
		c++;
		i++;
	}
	tmp = ft_memmove(buff, (buff + i), ft_strlen(buff + i));
	p[c] = '\0';
	return (p);
}

static char	*check_g(char *buff, int fd, int r, int cnt)
{
	char	*tmp;

	if (!r && buff[0] == '\0')
		return (0);
	tmp = malloc(1 * sizeof(char));
	tmp[0] = '\0';
	while (r || buff[0] != '\0')
	{
		while (buff[cnt])
		{
			if (buff[cnt] == '\n')
				return (create(buff, tmp, cnt + 1));
			cnt++;
		}
		tmp = create(buff, tmp, cnt);
		cnt = 0;
		r = read(fd, buff, 5);
		if (r < 0)
			free (tmp);
		if (r < 0)
			return (0);
		buff[r] = '\0';
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buff[1];
	int			r;

	r = 0;
	if (fd < 0)
		return (0);
	if (!buff[fd])
	{
		buff[fd] = malloc((5 + 1) * sizeof(char));
		if (!buff[fd])
			return (0);
		buff[fd][0] = '\0';
	}
	if (!buff[fd][0])
	{
		r = read(fd, buff[fd], 5);
		if (!(r > 0))
		{
			free(buff[fd]);
			buff[fd] = 0;
			return (0);
		}
		buff[fd][r] = '\0';
	}
	return (check_g(buff[fd], fd, r, 0));
}
