/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:45:18 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 08:07:24 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"

static int	ft_getsign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static long	ft_getabs(long n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static size_t	ft_numlen(long n)
{
	size_t	counter;

	counter = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*buf;
	int		sign;
	size_t	len;
	long	lngnum;

	sign = ft_getsign(n);
	lngnum = ft_getabs((long)n);
	len = ft_numlen(lngnum) + sign;
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	if (sign == 1)
		*buf = '-';
	*(buf + len--) = '\0';
	if (lngnum == 0)
		*(buf) = '0';
	while (lngnum)
	{
		*(buf + len) = (lngnum % 10) + '0';
		lngnum = lngnum / 10;
		if (len)
			len--;
	}
	return (buf);
}
