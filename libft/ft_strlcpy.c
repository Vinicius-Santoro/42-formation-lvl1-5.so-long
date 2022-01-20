/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:40:20 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:31:54 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destiny, const char *source, size_t destiny_size)
{
	size_t	source_size;
	size_t	index;

	if ((destiny || source) == 0)
		return (0);
	source_size = ft_strlen(source);
	index = 0;
	if (destiny_size > 0)
	{
		while (source[index] != '\0' && index < (destiny_size - 1))
		{
			destiny[index] = source[index];
			index++;
		}
		destiny[index] = '\0';
	}
	return (source_size);
}
