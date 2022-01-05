/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:47:49 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/16 13:52:32 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	index;

	index = (int) ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == (unsigned char) c)
		{
			return ((char *)str + index);
		}
		index--;
	}
	return (NULL);
}
