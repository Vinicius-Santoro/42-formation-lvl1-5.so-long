/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:48:56 by ldatilio          #+#    #+#             */
/*   Updated: 2021/09/16 14:13:21 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= len)
		len = s_len - start;
	if (start > s_len)
		return (ft_strdup(""));
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	else
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
