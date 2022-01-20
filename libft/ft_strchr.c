/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:04:31 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 11:32:04 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	unsigned char	character_aux;

	character_aux = (unsigned char) character;
	while (*string != '\0' && character_aux != *string)
		string++;
	if (character_aux == *string)
		return ((char *)string);
	return (NULL);
}
