/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:22:28 by vnazioze          #+#    #+#             */
/*   Updated: 2021/09/15 12:10:08 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*auxiliary;

	auxiliary = malloc(number * size);
	if (auxiliary == NULL)
		return (auxiliary);
	ft_bzero(auxiliary, size * number);
	return (auxiliary);
}
