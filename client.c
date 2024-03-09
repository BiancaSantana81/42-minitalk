/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/09 19:04:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int g_is_received;

void is_received(int sig)
{
    if (sig == SIGUSR1)
        g_is_received = 1;
}

void send_signal(int pid, char c)
{
    static int i;
    static char bit;

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

void send_message(int pid, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        send_signal(pid, str[i]);
        i++;
    }
    send_signal(pid, '\n');
}

int main(int argc, char **argv)
{
    struct sigaction siga;
    __pid_t          pid;

    if(argc != 3)
    return (ft_printf("Invalid number of arguments.\n"));
    siga.sa_flags = 0;
    siga.sa_handler = is_received;
    sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
    pid = ft_atoi(argv[1]);
    send_message(pid, argv[2]);
}