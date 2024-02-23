/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:40:41 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/16 21:27:43 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	*ft_memset(void *array, int c, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ptr;

// 	i = 0;
// 	ptr = array;
// 	while (i < n)
// 	{
// 		ptr[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (array);
// }
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*space;
// 	size_t	bytes;

// 	bytes = size * count;
// 	if (count == 0 || size == 0)
// 		return (ft_calloc(1, 1));
// 	if (bytes / size != count)
// 		return (0);
// 	space = malloc(count * size);
// 	if (space != NULL)
// 		ft_bzero(space, count * size);
// 	return (space);
// }

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
// char	*ft_strdup(const char *s1)
// {
// 	char	*s1_cpy;
// 	int		i;

// 	i = 0;
// 	while (s1[i] != '\0')
// 		i++;
// 	s1_cpy = (char *)malloc(i + 1);
// 	if (s1_cpy == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		s1_cpy[i] = (char)s1[i];
// 		i++;
// 	}
// 	s1_cpy[i] = '\0';
// 	return (s1_cpy);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*sub_s;
// 	size_t			str_len;

// 	if (s == 0)
// 		return (0);
// 	str_len = ft_strlen(s);
// 	if (str_len < start)
// 		return (ft_strdup(""));
// 	if (len > str_len - start)
// 		len = str_len - start;
// 	sub_s = (char *)malloc(len + 1);
// 	if (sub_s == NULL)
// 		return (NULL);
// 	ft_strlcpy(sub_s, s + start, len + 1);
// 	return (sub_s);
// }
int	count_word(const char *s, char c)
{
	int	words;
	int	i;
	int	prev_i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		prev_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (prev_i != i)
			words++;
	}
	return (words);
}

char	**free_all(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (0);
}

char	**ft_short(const char *s, char c, char **res, int c_word)
{
	int	prev_i;
	int	temp_count;
	int	i;

	temp_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		prev_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (prev_i != i && temp_count < c_word)
		{
			res[temp_count] = ft_substr(s, prev_i, i - prev_i);
			if (!res[temp_count])
				return (free_all(res));
			temp_count++;
		}
	}
	res[temp_count] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		c_word;

	c_word = count_word(s, c);
	res = ft_calloc(c_word + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = ft_short(s, c, res, c_word);
	return (res);
}
// #include <stdio.h>
// int    main(void)
// {
// // s = ft_split();
// 	char *s = "      split       this for   me  !       ";

//         char **ns = ft_split(s, ' ');
// 		printf("%p\n", ns);

// 	// printf("Result 1:\n");
// 	// if (!ns)
// 	// 	printf("Test\n");
// 	// if (ns[0])
// 	// 	printf("Ok\n");
//     for (int i = 0; ns[i] != 0; i++) {
//         printf("[%d]: %s\n", i, ns[i]);
//         free(ns[i]);
//     }
// 	free (ns);
// 	// system("leaks a.out");
//     return (0);
// }
