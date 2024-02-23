/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:47:38 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/17 18:22:50 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/
// #include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("isprint number %d\n isprint character %d\n isprint other %d\n", 
	isprint('0'), isprint('z'), isprint('|'));
	printf("number %d\n character %d\n other %d\n", 
	ft_isprint('0'), ft_isprint('z'), ft_isprint('|'));
	return (0);
}*/
