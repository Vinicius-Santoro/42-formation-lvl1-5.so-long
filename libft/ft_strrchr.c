/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:38:16 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/16 13:08:43 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int character)
{
	int	index;

	index = (int) ft_strlen(string);
	while (index >= 0)
	{
		if (string[index] == (unsigned char) character)
		{
			return ((char *)string + index);
		}
		index--;
	}
	return (NULL);
}
