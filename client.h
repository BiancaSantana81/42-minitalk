/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:41:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/03/09 18:46:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>

/* Ao receber um sinal do servidor, a função is_received é chamada e altera o valor da variável global "g_is_received" para 1. */
void is_received(int sig);

#endif