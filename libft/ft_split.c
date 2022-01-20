/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:13:37 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 14:25:22 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	quantity_string(char const *str, char del);
static void		auxiliary_split(char const *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	char	**auxiliary_array;

	if (s == NULL)
		return (NULL);
	auxiliary_array = ft_calloc(quantity_string(s, c) + 1, sizeof(char *));
	if (auxiliary_array == NULL)
		return (NULL);
	auxiliary_split(s, c, auxiliary_array);
	return (auxiliary_array);
}

static void	auxiliary_split(char const *s, char c, char **array)
{
	size_t	i;
	size_t	char_i;
	size_t	array_i;

	i = 0;
	array_i = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			char_i = 0;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
				char_i++;
			}
			array[++array_i] = ft_calloc(char_i + 1, sizeof(char));
			ft_strlcpy(array[array_i], &s[i - char_i], char_i + 1);
		}
	}
}

static size_t	quantity_string(char const *str, char del)
{
	size_t	quantity_str;
	size_t	index;

	quantity_str = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (del == str[index])
		{
			index++;
		}
		else
		{
			while (str[index] != del && str[index] != '\0')
			{
				index++;
			}
			quantity_str++;
		}
	}
	return (quantity_str);
}
