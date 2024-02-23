/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:19:00 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/13 17:15:41 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	if (!arr1 && !arr2)
		return (0);
	while (*arr1 == *arr2 && ++i < n)
	{
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
}
// int	main(void)
// {
// 	printf("%d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
// 	printf("%d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
// }
/*
int main(void)
{
   	int	a[] = {1, 2, 3, 4};
   	int	b[] = {1, 2, 3, 4, 5};
   	int	c[] = {1, 2, 3, 4};
	int	d[] = {0, 1, 2, 3};
	int	f[] = {5, 6, 6, 8};

	printf("%d\n", ft_memcmp((const void *)a,(const void *)b,(size_t)3));
	printf("%d\n", memcmp((const void *)a,(const void *)b,(size_t)3));
	printf("\n");

	printf("%d\n", ft_memcmp((const void *)b,(const void *)c,(size_t)5));
	printf("%d\n", memcmp((const void *)b,(const void *)c,(size_t)5));
	printf("\n");

	printf("%d\n", ft_memcmp((const void *)c,(const void *)d,(size_t)4));
	printf("%d\n", memcmp((const void *)c,(const void *)d,(size_t)4));
	printf("\n");

	printf("%d\n", ft_memcmp((const void *)d,(const void *)c,(size_t)3));
	printf("%d\n", memcmp((const void *)d,(const void *)c,(size_t)3));
	printf("\n");

	printf("%d\n", ft_memcmp((const void *)d,(const void *)f,(size_t)6));
	printf("%d\n", memcmp((const void *)d,(const void *)f,(size_t)6));
	printf("\n");

	printf("%d\n", ft_memcmp((const void *)f,(const void *)d,(size_t)6));
	printf("%d\n", memcmp((const void *)f,(const void *)d,(size_t)6));

	return (0);
}*/
