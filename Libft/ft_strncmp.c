/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:12:12 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/09 17:21:20 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	if (i < n)
		return (-str2[i]);
	return (0);
}
/*
int main(void)
{
	char *s1 = "Cat";
	char *s2 = "cat";
	char *s3 = "cat";
	char *s4 = "cats";
	char *s5 = "cats are the best!";

	printf("%d\n", ft_strncmp(s1,s2,3));
	printf("%d\n", strncmp(s1,s2,3));
	printf("\n");

	printf("%d\n", ft_strncmp(s2,s3,5));
	printf("%d\n", strncmp(s2,s3,5));
	printf("\n");

	printf("%d\n", ft_strncmp(s3,s4,4));
	printf("%d\n", strncmp(s3,s4,4));
	printf("\n");

	printf("%d\n", ft_strncmp(s4,s3,3));
	printf("%d\n", strncmp(s4,s3,3));
	printf("\n");

	printf("%d\n", ft_strncmp(s4,s5,6));
	printf("%d\n", strncmp(s4,s5,6));
	printf("\n");

	printf("%d\n", ft_strncmp(s5,s4,6));
	printf("%d\n", strncmp(s5,s4,6));

	return (0);
} */
