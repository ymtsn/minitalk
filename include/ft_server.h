/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:52:17 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 01:13:23 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_H
# define FT_SERVER_H
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# define ETX 0x03
# define BUFSIZE 5120
# define SLEEPTIME 150
# define INITIAL_FAIL_MSG "initialization failed try again"
# define KILL_FAIL_MSG "kill failed"
# define ACK_LATE_MSG "ack message is too late"
# define MALLOC_FAIL_MSG "malloc failed"
int		ft_printf(const char *fmt, ...);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_fstrjoin(char *s1, size_t size);
#endif
