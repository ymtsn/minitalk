/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsuna <ymatsuna@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:03:50 by ymatsuna          #+#    #+#             */
/*   Updated: 2022/03/01 00:44:21 by ymatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client_bonus.h"

volatile sig_atomic_t	g_sign_frm_s;

static void	ft_myhandler(int signo, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	g_sign_frm_s = signo;
}

static void	ft_error(char *msg, void(*f)(void *), void *arg)
{
	ft_printf("%s\n", msg);
	if (f != NULL)
		f(arg);
	exit (EXIT_FAILURE);
}

static int	ft_init_client(int argc, char *argv, pid_t *argpid, char **mypid)
{
	struct sigaction	act;
	long				checkpid;

	if (argc <= 2)
		return (1);
	checkpid = ft_atoi(argv);
	if (checkpid < MYPIDMIN || checkpid > MYPIDMAX)
		return (1);
	*argpid = (pid_t)checkpid;
	ft_bzero(&act, sizeof(act));
	act.sa_flags = 0;
	act.sa_sigaction = ft_myhandler;
	if ((sigemptyset(&act.sa_mask) < 0) || (sigaction(SIGUSR1, &act, NULL) < 0))
		return (1);
	*mypid = ft_itoa((int)getpid());
	if (*mypid == NULL)
		return (1);
	if (**mypid == '-')
	{
		free(*mypid);
		return (1);
	}
	return (0);
}

static void	ft_send(char *str, pid_t argpid, size_t bytes)
{
	unsigned char	c;
	unsigned char	bitfinder;

	while (bytes != 0)
	{
		c = *str;
		bytes--;
		if (bytes)
			str++;
		bitfinder = (unsigned char)0b10000000;
		while (bitfinder)
		{
			usleep(SLEEPTIME);
			if (kill(argpid, SIGUSR1 + ((c & bitfinder) == bitfinder)) < 0)
				ft_error(KILL_FAIL_MSG, NULL, NULL);
			bitfinder = bitfinder >> 1;
		}
	}
}

int	main(int argc, char *argv[])
{
	pid_t			argpid;
	int				argvindex;
	static char		*mypid = NULL;
	static char		etx = ETX;

	if (ft_init_client(argc, argv[1], &argpid, &mypid) == 1)
		ft_error(INITIAL_FAIL_MSG, NULL, NULL);
	kill(argpid, SIGUSR1);
	usleep(SLEEPTIME);
	ft_send(mypid, argpid, ft_strlen(mypid));
	ft_send(&etx, argpid, 1);
	free(mypid);
	argvindex = 2;
	while (argvindex + 1 <= argc)
	{
		ft_send(argv[argvindex], argpid, ft_strlen(argv[argvindex]));
		argvindex++;
	}
	ft_send(&etx, argpid, 1);
	while (g_sign_frm_s != SIGUSR1 && argvindex--)
		usleep(SLEEPTIME);
	if (g_sign_frm_s != SIGUSR1)
		ft_error(ACK_LATE_MSG, NULL, NULL);
	ft_printf("%s\n", "ACK message arrived from the server");
	return (0);
}
