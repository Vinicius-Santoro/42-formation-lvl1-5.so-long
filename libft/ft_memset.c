/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:29:38 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/06 15:29:42 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t lengh)
{
	size_t	index;

	index = 0;
	while (index < lengh)
	{
		((unsigned char *) str)[index] = c;
		index++;
	}
	return (str);
}
