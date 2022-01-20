/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:45:11 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:19:34 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int	signal;
	int	final_return;

	signal = 1;
	final_return = 0;
	while (*string == ' ' || *string == '\n' || *string == '\t'
		|| *string == '\v' || *string == '\f' || *string == '\r')
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			signal = -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		final_return = (final_return * 10) + (*string - '0');
		string++;
	}
	return (final_return * signal);
}
