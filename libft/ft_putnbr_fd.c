/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:19:46 by ymatsuna          #+#    #+#             */
/*   Updated: 2021/11/17 20:33:58 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	int		wn;

	ln = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ln = ln * -1;
	}
	if (ln >= 10)
		ft_putnbr_fd((int)(ln / 10), fd);
	wn = (int)(ln % 10 + '0');
	write(fd, &wn, 1);
}
