/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:01:42 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/08 21:25:49 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h> 

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
int main(void) 
{
    char *original = NULL;
    char buffer1 = NULL;
	char buffer2 = NULL;

    size_t n = 15;
	ft_memmove(buffer1, original, n);
	memmove(buffer2, original, n);

    // Compare the results
    int comparison = memcmp(buffer1, buffer2, n); // Compare the first n bytes

    if (comparison == 0) {
        printf("ft_memmove and memmove produced the same results.\n");
    } else {
        printf("Results differ between ft_memmove and memmove.\n");
    }

    return 0;
}*/
