/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:04:11 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:23:23 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destiny, const void *source, size_t lengh)
{
	size_t	index;
	char	*destiny_aux;
	char	*source_aux;

	index = 0;
	destiny_aux = (char *)destiny;
	source_aux = (char *)source;
	while (index < lengh)
	{
		destiny_aux[index] = source_aux[index];
		index++;
	}
	return (destiny);
}
