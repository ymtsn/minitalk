/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_csper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:32:16 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/01/03 15:07:07 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fmt_c(va_list *ap, t_prf *ag)
{
	unsigned char	uc;

	uc = (unsigned char)va_arg(*ap, int);
	write(1, &uc, 1);
	ag->writelen = 1;
}

void	ft_fmt_s(va_list *ap, t_prf *ag)
{
	char	*s;
	size_t	size;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		ag->writelen = 6;
		return ;
	}
	size = ft_strlen(s);
	if (size >= INT_MAX)
	{
		ag->writelen = ERROR;
		return ;
	}
	ft_putstr_fd(s, 1);
	ag->writelen = size;
}

void	ft_fmt_percent(t_prf *ag)
{
	ft_putchar_fd('%', 1);
	ag->writelen = 1;
}
