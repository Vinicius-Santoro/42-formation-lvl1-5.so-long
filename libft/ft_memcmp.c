/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:17:47 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:24:00 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *string1, const void *string2, size_t lengh)
{
	size_t			index;
	unsigned char	*string1_aux;
	unsigned char	*string2_aux;

	index = 0;
	string1_aux = (unsigned char *) string1;
	string2_aux = (unsigned char *) string2;
	while (index < lengh)
	{
		if ((string1_aux[index]) != (string2_aux[index]))
		{
			return (string1_aux[index] - string2_aux[index]);
		}
		index++;
	}
	return (0);
}
