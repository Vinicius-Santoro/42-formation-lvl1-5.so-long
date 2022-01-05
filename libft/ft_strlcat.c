/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:11:04 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/15 20:43:12 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	i;

	if (destsize <= ft_strlen(dest))
		return (destsize + ft_strlen(src));
	destlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && destlen + i < destsize - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
