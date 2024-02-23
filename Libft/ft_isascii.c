/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:18:22 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/17 18:22:23 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/
// #include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("digit check %d\n character check %d\n other check %d\n", 
	ft_isascii('3'), ft_isascii('j'), ft_isascii('+'));
	printf("isalnum digit %d\n isalnum character %d\n isalnum other %d\n", 
	isascii('3'), isascii('j'), isascii('+'));
}*/
