/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:22:41 by bsantana          #+#    #+#             */
/*   Updated: 2024/02/29 10:17:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int t)
{
	int	s_len;

	s_len = 0;
	if (t < 0)
		s_len = 1;
	while (t)
	{
		t /= 10;
		s_len++;
	}
	return (s_len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		count_s;
	long	num;

	count_s = ft_count(n);
	num = (long)n;
	s = (char *)ft_calloc((count_s + 1), 1);
	if (s == NULL)
		return (NULL);
	s[count_s] = '\0';
	if (num < 0)
		num *= -1;
	while (count_s > 0)
	{
		count_s--;
		s[count_s] = '0' + (num % 10);
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
