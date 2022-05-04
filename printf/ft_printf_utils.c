/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:04:44 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/12/30 08:39:14 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_num_length_lng(long n, int radix)
{
	size_t	counter;

	if (!n)
		return (1);
	counter = 0;
	if (n < 0)
	{
		n = -1 * n;
		counter = 1;
	}
	while (n)
	{
		n = n / radix;
		counter++;
	}
	return (counter);
}

size_t	ft_get_num_length_ull(unsigned long long n, int radix)
{
	size_t	counter;

	if (!n)
		return (1);
	counter = 0;
	while (n)
	{
		n = n / radix;
		counter++;
	}
	return (counter);
}

void	ft_putnbr_ull_base(unsigned long long nb, char type, unsigned int radix)
{
	char	*base;

	if (type == 'x' || type == 'o')
		base = "0123456789abcdefg";
	else
		base = "0123456789ABCDEFG";
	if (nb >= radix)
		ft_putnbr_ull_base(nb / radix, type, radix);
	write(1, base + (nb % radix), 1);
}
