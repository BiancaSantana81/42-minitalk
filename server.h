/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:53 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/01 11:31:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/* Bibliotecas */

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>

/*
 * This function handles the signals that the server receives from the client.
 * It uses SIGUSR1 and SIGUSR2 as communication signals.
 * With each signal received from the client,
 * the server interprets it as follows:
 * - For SIGUSR1, a bit 1 is added to the current character.
 * - For SIGUSR2, a bit of 0 is added to the current character.
 * 
 * After accumulating eight bits, the
 * writes the corresponding character to the standard output (stdout),
 * resets the bit counter and the character
 * accumulator to zero for the next reading.
 * It then sends a SIGUSR1 signal back to the
 * client to confirm that it is ready to receive more data.
 * 
 * Parameters:
 * - signum: the number of the signal received.
 * - info: structure containing information
 * about the received signal, including the client's PID.
 * - context: context of the signal.
 */

void	handler_signal(int signum, siginfo_t *info, void *context);

#endif