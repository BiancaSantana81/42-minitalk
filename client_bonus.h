/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/01 13:38:12 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

/* Libraries */

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
 * Function called when receiving a signal from the server.
 * Changes the value of the global variable "g_is_received"
 * to 1 if the signal received is SIGUSR1.
 * When it receives SIGUSR2, it prints a message on the
 * stdout indicating that the message was received by the client.
 * 
 * Parameters:
 * - sig: the signal received.
 */
void	is_received(int sig);

/*
 * Function for sending a character to a
 * process with the SIGUSR1 or SIGUSR2 signal.
 * The character is sent bit by bit, where each
 * bit is converted into a signal and sent
 * to the process identified by 'pid'.
 *
 * Parameters:
 * - pid: identifier of the target process.
 * - c: character to be sent.
 */
void	send_signal(int pid, char c);

/*
 * Function to send a message to a server process.
 * It loops through the given string and sends
 * each character to the server using the send_signal() function.
 * After sending the string, it sends a "\n" and a "\0" to the server.
 *
 * Parameters:
 * - pid: identifier of the server process.
 * - str: string containing the message to be sent.
 */
void	send_message(int pid, char *str);

#endif