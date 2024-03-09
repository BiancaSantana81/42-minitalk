/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:53 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/09 18:18:19 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>

/* Esta função manipula os sinais que o servidor recebe do cliente. Para isso, utiliza SIGUSR1 e SIGUSR2 como sinais de comunicação. A cada sinal recebido do cliente, o servidor interpreta-o de acordo com o seguinte:

    - Para SIGUSR1, um bit 1 é adicionado ao caractere atual.
    - Para SIGUSR2, um bit 0 é adicionado ao caractere atual.
    
    Após acumular oito bits, a função escreve o caractere correspondente na saída padrão (stdout) e zera o contador de bits e o acumulador do caractere para a próxima leitura. Em seguida, envia um sinal SIGUSR1 de volta ao cliente para confirmar que está pronto para receber mais dados.*/
void handler_signal(int signum, siginfo_t *info, void *context);


#endif