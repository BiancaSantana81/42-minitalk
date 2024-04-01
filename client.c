/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/01 12:53:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/*
* By declaring the variable g_is_received as global, we guarantee
* that its value can be accessed and manipulated correctly by all
* the functions in the program. This is necessary  to coordinate
* communication between the processes involved, where different
* parts of the code need to signal when a signal is received or processed.
 */
int	g_is_received;

int	valid_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (1);
		i++;
	}
	return (0);
}

void	is_received(int sig)
{
	if (sig == SIGUSR1)
		g_is_received = 1;
}

void	send_signal(int pid, char c)
{
	static int	i;
	static char	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		g_is_received = 0;
		bit = c >> i & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		while (!g_is_received)
			;
		i++;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_signal(pid, str[i]);
		i++;
	}
	send_signal(pid, '\n');
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	siga;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments.\n"));
	if (valid_pid(argv[1]))
		return (ft_printf("Insert a valid PID.\n"));
	siga.sa_flags = 0;
	siga.sa_handler = is_received;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}
