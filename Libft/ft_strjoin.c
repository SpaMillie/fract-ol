/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:43:01 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/04 14:15:04 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

static char	*ft_stradd(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*space_to_fill;
	size_t	n;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = 0;
	n = i + ft_strlen((char *)s2) + 1;
	space_to_fill = (char *)malloc(n);
	if (space_to_fill == NULL)
		return (NULL);
	space_to_fill = ft_stradd((char *)s1, space_to_fill);
	while (s2[j] != '\0')
	{
		space_to_fill[i] = s2[j];
		i++;
		j++;
	}
	space_to_fill[i] = '\0';
	return (space_to_fill);
}
/*
int	main(void)
{
	printf("%s\n", ft_strjoin("Speak to me", ", lover"));
	return (0);
}*/
