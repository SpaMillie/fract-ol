/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:37:05 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/10 14:23:24 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"
/*
size_t	ft_strlen(const char *str);
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	i = 0;
	if (dst != 0)
		dst_len = ft_strlen(dst);
	if (dst_len > dstsize)
		dst_len = dstsize;
	if (dstsize == 0 || dstsize == dst_len)
		return (src_len + dst_len);
	while (src[i] != '\0' && (i + dst_len) < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	str1[] = "Heyyo";
	char	str2[20] = "Heyya";
	size_t	r;

	r = ft_strlcat(str2, str1, 20);
	printf("check src: %s\ncheck dst %s\ncheck srcsize %zu\n", str1, str2, r);
	return (0);
}*/
