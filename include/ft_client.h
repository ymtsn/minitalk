/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:52:17 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 16:16:08 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLIENT_H
# define FT_CLIENT_H
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# define ETX 0x03
# define SLEEPTIME 150
# define MYPIDMIN 100
# define MYPIDMAX 99998
# define INITIAL_FAIL_MSG "initialization failed try again"
# define KILL_FAIL_MSG "kill failed"
# define ACK_LATE_MSG "ack message is too late"
int		ft_printf(const char *fmt, ...);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
#endif
