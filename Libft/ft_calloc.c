/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:58:03 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/17 17:07:45 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	bytes;

	bytes = size * count;
	if (size != 0)
		if (bytes / size != count || bytes < 0)
			return (0);
	space = malloc(count * size);
	if (space != NULL)
		ft_bzero(space, count * size);
	return (space);
}
