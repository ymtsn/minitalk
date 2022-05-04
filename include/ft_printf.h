/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:52:17 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/02/21 11:35:29 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "libft.h"
# define ERROR -1
typedef struct s_prtf{
	ssize_t	writelen;
}	t_prf;
void	ft_fmt_c(va_list *ap, t_prf *ag);
void	ft_fmt_s(va_list *ap, t_prf *ag);
void	ft_fmt_percent(t_prf *ag);
void	ft_fmt_di(va_list *ap, t_prf *ag);
void	ft_fmt_u(va_list *ap, t_prf *ag);
void	ft_fmt_xX(va_list *ap, t_prf *ag, char type, int rad);
void	ft_fmt_p(va_list *ap, t_prf *ag, char type, int rad);
void	ft_putnbr_ull_base(unsigned long long nb, char type, unsigned int rad);
size_t	ft_get_num_length_lng(long n, int radix);
size_t	ft_get_num_length_ull(unsigned long long n, int radix);
int		ft_printf(const char *fmt, ...);
#endif
