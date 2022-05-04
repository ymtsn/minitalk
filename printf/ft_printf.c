/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:07:01 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 15:07:03 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_out_ap(const char *fmt, t_prf *ag, va_list *ap)
{
	ag->writelen = 0;
	if (*fmt == 'c')
		ft_fmt_c(ap, ag);
	if (*fmt == 's')
		ft_fmt_s(ap, ag);
	if (*fmt == 'p')
		ft_fmt_p(ap, ag, 'x', 16);
	if (*fmt == '%')
		ft_fmt_percent(ag);
	if (*fmt == 'd' || *fmt == 'i')
		ft_fmt_di(ap, ag);
	if (*fmt == 'u')
		ft_fmt_u(ap, ag);
	if (*fmt == 'x')
		ft_fmt_xX(ap, ag, 'x', 16);
	if (*fmt == 'X')
		ft_fmt_xX(ap, ag, 'X', 16);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			ret;
	t_prf		ag;

	ret = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_out_ap(++fmt, &ag, &ap);
			if (ag.writelen == ERROR)
			{
				va_end(ap);
				return (-1);
			}
			ret += ag.writelen;
		}
		else
			ret += write(1, fmt, 1);
		if (*fmt)
			fmt++;
	}
	va_end(ap);
	return (ret);
}
