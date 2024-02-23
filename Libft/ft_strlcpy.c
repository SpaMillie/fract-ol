/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:41:54 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/13 19:35:57 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> 
//  size_t	ft_strlen(char *str)
// {
// 	size_t	i;
// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i + 1 < dstsize && i < srcsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
// int	main(void)
// {
// 	char	str1[] = "";
// 	char	str2[10];
// 	size_t	r;

// 	r = ft_strlcpy(str2, str1, 6);
// 	printf("check src: %s\ncheck dst %s\ncheck srcsize %zu\n", str1, str2, r);
// 	return (0);	
// }
