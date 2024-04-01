/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/01 10:24:59 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	handler_signal(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	if (!context)
		return ;
	if (signum == SIGUSR1)
		c += 1 << i;
	else if (signum == SIGUSR2)
		c += 0 << i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	siga;

	pid = getpid ();
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = handler_signal;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	return (0);
}
