/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:29:37 by vnazioze          #+#    #+#             */
/*   Updated: 2022/01/16 04:15:25 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*string;

	index = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	string = (char *)malloc (sizeof(char) * ft_strlen(s) + 1);
	if (string == NULL)
		return (NULL);
	while (s[index] != '\0')
	{
		string[index] = f(index, s[index]);
		index++;
	}
	string[index] = '\0';
	return (string);
}
