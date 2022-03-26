/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:31:38 by aaammari          #+#    #+#             */
/*   Updated: 2022/03/25 23:31:52 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	get_pid(void)
{
	int		len;
	char	*str_pid;

	str_pid = ft_itoa(getpid());
	len = ft_strlen(str_pid);
	write(1, str_pid, len);
	write(1, "\n", 1);
	free(str_pid);
}

void	handler(int signo, siginfo_t *info, void *other)
{
	static int	i;
	static char	c;
	static int	pid;

	(void)other;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		i = 0;
		c = 0;
		pid = info->si_pid;
	}
	c = (c << 1) | (signo - 30);
	i++;
	if (i == 8 && info->si_pid)
	{
		write(1, &c, 1);
		if (c == 0)
			kill(pid, SIGUSR1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	get_pid();
	while (1)
		pause();
	return (0);
}
