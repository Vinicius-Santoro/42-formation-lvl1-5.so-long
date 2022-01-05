/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 22:50:32 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/09 18:50:23 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*a;
	size_t	len;
	long	nb;

	nb = n;
	len = numlen(n);
	a = malloc(sizeof(char) * (len + 1));
	if (a == 0)
		return (NULL);
	if (nb < 0)
	{
		a[0] = '-';
		nb = -nb;
	}
	a[len--] = '\0';
	if (nb == 0)
		a[0] = '0';
	while (nb)
	{
		a[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}
