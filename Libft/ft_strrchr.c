/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:44:00 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/13 17:18:58 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s) + 1;
	ptr = (char *)s;
	while (i--)
	{
		if (s[i] == (char)c)
		{
			ptr = (char *)&s[i];
			return (ptr);
		}
	}
	ptr = NULL;
	return (ptr);
}
// int	main(void)
// {
// 	char	*str = "abbbbbbbb";

// 	printf("%c\n%s\n", '\0', ft_strrchr(str, '\0'));
// 	return (0);
// }
