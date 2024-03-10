/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/10 12:27:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

/*  
 * Ao declarar a variável g_is_received como global, garantimos que seu valor pode ser 
 * acessado e manipulado corretamente por todas as funções do programa. Isso é necessário 
 * para coordenar a comunicação entre os processos envolvidos, onde diferentes partes do 
 * código precisam sinalizar quando um sinal é recebido ou processado. 
 */
int g_is_received;

int valid_pid(char *pid)
{
    int i;

    i = 0;
    while (pid[i])
    {
        if (!ft_isdigit(pid[i]))
            return (1);
        i++;
    }
    return (0);
}

void is_received(int sig)
{
    if (sig == SIGUSR1)
        g_is_received = 1;
    if (sig == SIGUSR2)
        ft_printf("Signal received!\n");
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
    send_signal(pid, '\0');
}

int main(int argc, char **argv)
{
    struct sigaction siga;
    __pid_t          pid;

    if(argc != 3)
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