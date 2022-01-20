/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 20:16:34 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:26:49 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destiny, const char *source, size_t destiny_size)
{
	size_t	index;
	size_t	lengh;

	if (destiny_size <= ft_strlen(destiny))
		return (destiny_size + ft_strlen(source));
	index = ft_strlen(destiny);
	lengh = 0;
	while (source[lengh] != '\0' && index + 1 < destiny_size)
	{
		destiny[index] = source[lengh];
		index++;
		lengh++;
	}
	destiny[index] = '\0';
	return (ft_strlen(destiny) + ft_strlen(&source[lengh]));
}
