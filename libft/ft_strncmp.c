/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:48:31 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/09 18:11:58 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t lengh)
{
	size_t	i;

	i = 0;
	if (lengh == 0)
		return (0);
	while ((string1[i] == string2[i]) && (string1[i] != '\0' && i < lengh - 1))
	{
		i++;
	}
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
