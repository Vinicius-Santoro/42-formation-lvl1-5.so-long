/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:16:37 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:22:09 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int character, size_t lengh)
{
	size_t			index;
	unsigned char	*string_aux;
	unsigned char	character_aux;

	index = 0;
	string_aux = (unsigned char *) string;
	character_aux = (unsigned char) character;
	while (index < lengh)
	{
		if (string_aux[index] == character_aux)
		{
			return ((void *)(index + string));
		}
		index++;
	}
	return (0);
}
