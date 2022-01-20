/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:06:48 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 11:30:16 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	string_lengh;

	if (s == NULL)
		return (NULL);
	string_lengh = ft_strlen(s);
	if (string_lengh <= len)
		len = string_lengh - start;
	if (start > string_lengh)
		return (ft_strdup(""));
	new_string = ft_calloc(len + 1, sizeof(char));
	if (new_string == NULL)
		return (NULL);
	else
		ft_strlcpy(new_string, s + start, len + 1);
	return (new_string);
}
