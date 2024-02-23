/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:33:46 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/13 20:25:37 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
// size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
// {
// 	size_t	srcsize;
// 	size_t	i;

// 	i = 0;
// 	srcsize = ft_strlen(src);
// 	if (dstsize > 0)
// 	{
// 		while (i + 1 < dstsize && i < srcsize)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (srcsize);
// }
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			str_len;

	if (s == 0)
		return (0);
	str_len = ft_strlen(s);
	if (str_len < start)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub_s = (char *)malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, s + start, len + 1);
	return (sub_s);
}
// int	main(void)
// {
// 	char *s = "";
// 	char *s1 = ft_substr(s, 1, 1);

// 	printf("String s %d\n", (int)s[0]);
// 	printf("String s1 %d\n", (int)s1[0]);
// 	printf("String: %s\nsubstring: %s\n%d\n", s, s1, strncmp(s1, s, 1));
// 	free (s1);
// 	return (0);
// }
