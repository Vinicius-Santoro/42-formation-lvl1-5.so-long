/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:57:29 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 16:41:27 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_decomposition(signed long int number, char *str, int *auxiliary)
{
	if (number > 9)
	{
		ft_decomposition(number / 10, str, auxiliary);
		ft_decomposition(number % 10, str, auxiliary);
	}
	else
		str[(*auxiliary)++] = number + '0';
}

static size_t	ft_lengh(int number)
{
	size_t	lengh;

	lengh = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		lengh++;
	while (number != 0)
	{
		number /= 10;
		lengh++;
	}
	return (lengh);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		index;

	string = malloc(sizeof(char) * (ft_lengh(n) + 1));
	if (string == NULL)
		return (NULL);
	index = 0;
	if (n == -2147483648)
	{
		string[index++] = '-';
		string[index++] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		string[index++] = '-';
		n *= -1;
	}
	ft_decomposition(n, string, &index);
	string[index] = '\0';
	return (string);
}
