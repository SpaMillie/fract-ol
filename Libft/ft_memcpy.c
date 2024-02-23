/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:00:10 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/08 17:32:41 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memcpy() function copies n bytes from memory area src to memory
//      area dst.  If dst and src overlap, behavior is undefined.  Applica-
//      tions in which dst and src might overlap should use memmove(3)
//      instead.
//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*array_d;
	unsigned char	*array_s;
	size_t			i;

	array_d = (unsigned char *)dst;
	array_s = (unsigned char *)src;
	i = 0;
	while (i < n && src != dst)
	{
		array_d[i] = array_s[i];
		i++;
	}
	return (dst);
}
// int	main(void)
// {
// 	int ar1[] = {1, 2, 3, 4, 5};
// 	int	ar2[5];
// 	int	i;
// 	i = 0;
// 	while (i < 5)
// 		ar2[i++] = 0;
// 	ft_memcpy(ar2, ar1, 4 * 5);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("ar1 after: %d\n", ar1[i]);
// 		printf("ar2 after: %d\n", ar2[i]);
// 		i++;
// 	}
// 	return (0);
// }
