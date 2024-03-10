/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:53 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/10 11:10:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/* Bibliotecas */

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>

/*
 * Esta função manipula os sinais que o servidor recebe do cliente.
 * Utiliza SIGUSR1 e SIGUSR2 como sinais de comunicação.
 * A cada sinal recebido do cliente, o servidor interpreta-o da seguinte maneira:
 *    - Para SIGUSR1, um bit 1 é adicionado ao caractere atual.
 *    - Para SIGUSR2, um bit 0 é adicionado ao caractere atual.
 * 
 * Após acumular oito bits, a função escreve o caractere correspondente na saída padrão (stdout)
 * e zera o contador de bits e o acumulador do caractere para a próxima leitura.
 * Em seguida, envia um sinal SIGUSR1 de volta ao cliente para confirmar que está pronto para receber mais dados.
 * 
 * Parâmetros:
 *    - signum: o número do sinal recebido.
 *    - info: estrutura contendo informações sobre o sinal recebido, incluindo o PID do cliente.
 *    - context: contexto do sinal.
 */
void handler_signal(int signum, siginfo_t *info, void *context);

#endif