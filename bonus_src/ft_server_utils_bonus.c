/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:36:15 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 08:00:19 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

void	ft_bzero(void *s, size_t n)
{
	char	*buf;

	buf = (char *)s;
	while (n)
	{
		*buf++ = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	s = (char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return ((void *)s);
}

char	*ft_fstrjoin(char *s1, size_t size)
{
	char	*buf;
	char	*save;
	char	*temp;

	if (s1 == NULL)
		return (NULL);
	buf = (char *)ft_calloc(1, ft_strlen(s1) + size);
	if (buf == NULL)
		return (NULL);
	save = buf;
	temp = s1;
	while (*s1)
		*buf++ = *s1++;
	free(temp);
	return (save);
}

int	ft_atoi(const char *str)
{
	long	buf;
	int		sign;

	buf = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		buf = buf * 10 + (*str++ - '0');
	return ((int)(buf * sign));
}
