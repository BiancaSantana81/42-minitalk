/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/01 11:47:14 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/* Bibliotecas */

# include "libft/libft.h"
# include <signal.h>

/*
 * Function to check if the PID is made up of numbers only.
 * 
 * Parameters:
 * - pid: target process identifier.
 * 
 * Returns:
 * - 0 if the PID contains only numbers.
 * - 1 if the PID contains characters that are not numbers.
 */
int		valid_pid(char *pid);

/*
 * Function called when a signal is received from the server.
 * Changes the value of the global
 * variable "g_is_received" to 1 if the signal received is SIGUSR1.
 * 
 * Parameters:
 * - sig: the signal received.
 */
void	is_received(int sig);

/*
 * Função para enviar um caractere para um processo com o sinal SIGUSR1 ou SIGUSR2.
 * O caractere é enviado bit a bit, onde cada bit é convertido em um sinal e enviado
 * para o processo identificado por 'pid'.
 *
 * Parâmetros:
 *    - pid: identificador do processo destino.
 *    - c: caractere a ser enviado.
 */
void	send_signal(int pid, char c);

/*
 * Função para enviar uma mensagem para um processo servidor.
 * Percorre a string fornecida e envia cada caractere para o servidor
 * usando a função send_signal().
 *
 * Parâmetros:
 *    - pid: identificador do processo servidor.
 *    - str: string contendo a mensagem a ser enviada.
 */
void	send_message(int pid, char *str);

#endif