/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 23:30:46 by aaammari          #+#    #+#             */
/*   Updated: 2022/03/25 23:31:18 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	(void)sig;
	write(1, "message been send\n", 18);
}

void	send_c(int pid, char c)
{
	int	current_bit;

	current_bit = 7;
	while (current_bit >= 0)
	{
		kill(pid, (c >> current_bit & 1) + SIGUSR1);
		current_bit--;
		usleep(600);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	signal(SIGUSR1, handler);
	if (!av || ac != 3)
	{
		write(2, "errors", 6);
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_c(pid, av[2][i++]);
	send_c(pid, av[2][i]);
}
