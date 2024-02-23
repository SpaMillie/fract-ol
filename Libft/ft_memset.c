/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:19:43 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/03 13:44:43 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memset(void *array, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = array;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (array);
}
/*
int	main(void)
{
	char	str_old[] = "before your eyes";

	ft_memset(str_old, 'c', 4);
	printf("Watch it change %s\n", str_old);
	return (0);
}*/
