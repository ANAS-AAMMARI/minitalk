/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:36:09 by aaammari          #+#    #+#             */
/*   Updated: 2022/03/26 00:25:23 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

	if (!av || ac != 3)
	{
		write(2, "errors", 6);
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_c(pid, av[2][i++]);
}
