/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_diuxXp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:37:50 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 15:07:05 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fmt_di(va_list *ap, t_prf *ag)
{
	int		nb;
	size_t	size;

	nb = va_arg(*ap, int);
	size = ft_get_num_length_lng(nb, 10);
	ft_putnbr_long_fd(nb, 1);
	ag->writelen = size;
}

void	ft_fmt_u(va_list *ap, t_prf *ag)
{
	unsigned int	nb;
	size_t			size;

	nb = va_arg(*ap, unsigned int);
	size = ft_get_num_length_ull(nb, 10);
	ft_putnbr_long_fd(nb, 1);
	ag->writelen = size;
}

void	ft_fmt_xX(va_list *ap, t_prf *ag, char btype, int radix)
{
	unsigned int	nb;
	size_t			size;

	nb = va_arg(*ap, unsigned int);
	size = ft_get_num_length_ull(nb, radix);
	ft_putnbr_ull_base(nb, btype, radix);
	ag->writelen = size;
}

void	ft_fmt_p(va_list *ap, t_prf *ag, char btype, int radix)
{
	unsigned long long	nb;
	size_t				size;

	nb = (unsigned long long)va_arg(*ap, void *);
	size = ft_get_num_length_ull(nb, 16);
	size += write(1, "0x", 2);
	ft_putnbr_ull_base(nb, btype, radix);
	ag->writelen = size;
}
