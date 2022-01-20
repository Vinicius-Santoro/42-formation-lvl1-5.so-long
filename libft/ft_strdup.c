/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:07:51 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 08:47:26 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*duplicate_string;

	duplicate_string = (char *) malloc(ft_strlen(string) + 1);
	if (duplicate_string == NULL)
		return (NULL);
	else
		ft_memcpy(duplicate_string, string, ft_strlen(string) + 1);
	return (duplicate_string);
}
