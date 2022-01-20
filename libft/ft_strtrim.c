/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:57:18 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 10:58:51 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while ((*s1 != 0) && (ft_strchr(set, *s1) != 0))
		s1++;
	index = ft_strlen(s1);
	while (index != 0 && ft_strchr(set, s1[index]) != NULL)
		index--;
	return (ft_substr(s1, 0, index + 1));
}
