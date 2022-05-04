/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:04:44 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 00:32:39 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server_bonus.h"

volatile sig_atomic_t	g_sign_frm_c;

static void	ft_myhandler(int signo, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	g_sign_frm_c = signo;
}

static int	ft_init_server(void)
{
	struct sigaction	act;
	pid_t				checkpid;

	checkpid = getpid();
	if (checkpid == -1)
		return (1);
	ft_printf("%d\n", (int)checkpid);
	ft_bzero(&act, sizeof(act));
	act.sa_flags = 0;
	if (sigemptyset(&act.sa_mask) < 0)
		return (1);
	if (sigaddset(&act.sa_mask, SIGUSR1) < 0)
		return (1);
	if (sigaddset(&act.sa_mask, SIGUSR2) < 0)
		return (1);
	act.sa_sigaction = ft_myhandler;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		return (1);
	return (0);
}

static int	ft_recieve(char **bytes)
{
	unsigned char	bitchanger;
	unsigned char	onebyte;
	int				bytescount;

	bytescount = 0;
	while (bytescount < INT_MAX)
	{
		onebyte = 0;
		bitchanger = (unsigned char)0b10000000;
		while (bitchanger)
		{
			pause();
			if (g_sign_frm_c == SIGUSR2)
				onebyte = onebyte | bitchanger;
			bitchanger = bitchanger >> 1;
		}
		if (onebyte == ETX)
			return (bytescount);
		*(*bytes + bytescount++) = (char)onebyte;
		if (!(bytescount % (BUFSIZE - 1)))
			*bytes = (char *)ft_fstrjoin(*bytes, BUFSIZE);
		if (*bytes == NULL)
			exit(4);
	}
	return (bytescount);
}

int	main(void)
{
	char	*buf;
	int		bytescount;
	pid_t	clientpid;

	if (ft_init_server() == 1)
		return (1);
	while (1)
	{
		pause();
		buf = ft_calloc(1, BUFSIZE);
		if (buf == NULL)
			return (2);
		(void)ft_recieve(&buf);
		clientpid = (pid_t)ft_atoi((const char *)buf);
		bytescount = ft_recieve(&buf);
		write(1, buf, bytescount);
		free(buf);
		if (kill(clientpid, SIGUSR1) < 0)
			return (5);
	}
	return (0);
}
