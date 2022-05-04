/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:25:10 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 07:59:45 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client_bonus.h"

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
