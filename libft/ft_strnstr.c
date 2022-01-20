/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:15:33 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/14 16:31:16 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *sub_string, size_t lengh)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (sub_string[0] == '\0')
		return ((char *)string);
	while (string[i] != '\0')
	{
		j = 0;
		while (string[i + j] == sub_string[j] && (i + j) < lengh)
		{
			if (string[i + j] == '\0' && sub_string[j] == '\0')
				return ((char *)&string[i]);
			j++;
		}
		if (sub_string[j] == '\0')
			return ((char *)string + i);
		i++;
	}
	return (0);
}
