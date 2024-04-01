/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/01 10:02:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

/* Bibliotecas */

# include "libft/libft.h"
# include <signal.h>

/*
 * Função para verificar se o PID é composto apenas por números.
 * 
 * Parâmetros:
 *    - pid: identificador do processo destino.
 * 
 * Retorna:
 *    - 0 se o PID contém apenas números.
 *    - 1 se o PID contém caracteres que não são números.
 */
int		valid_pid(char *pid);

/*
 * Função chamada ao receber um sinal do servidor.
 * Altera o valor da variável global "g_is_received"
 * para 1 se o sinal recebido for SIGUSR1.
 * Ao receber SIGUSR2, ele imprime uma mensagem no
 * stdout indicando que a mensagem foi recebida pelo cliente.
 * 
 * Parâmetros:
 *    - sig: o sinal recebido.
 */
void	is_received(int sig);

/*
 * Função para enviar um caractere para um
 * processo com o sinal SIGUSR1 ou SIGUSR2.
 * O caractere é enviado bit a bit, onde cada
 * bit é convertido em um sinal e enviado
 * para o processo identificado por 'pid'.
 *
 * Parâmetros:
 *    - pid: identificador do processo destino.
 *    - c: caractere a ser enviado.
 */
void	send_signal(int pid, char c);

/*
 * Função para enviar uma mensagem para um processo servidor.
 * Percorre a string fornecida e envia
 * cada caractere para o servidor usando a função send_signal().
 * Após enviar a string, envia um '\n' e um '\0' para o servidor.
 *
 * Parâmetros:
 *    - pid: identificador do processo servidor.
 *    - str: string contendo a mensagem a ser enviada.
 */
void	send_message(int pid, char *str);

#endif