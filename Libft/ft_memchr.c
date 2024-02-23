/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:05:28 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/09 13:33:09 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (n > i && n != 0)
	{
		if (ptr[i] == (unsigned char)c)
		{
			ptr = (unsigned char *)&s[i];
			return (ptr);
		}
		else
			i++;
	}
	ptr = NULL;
	return (ptr);
}
/*
int	main(void)
{
	char *str = "Please call me Victor";

	printf("%c\n%s\n", 86, ft_memchr(str, 86, 5));
	return (0);
}*/
