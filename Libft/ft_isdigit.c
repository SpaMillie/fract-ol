/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:06:25 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/17 18:22:40 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>*/
// #include "libft.h"

int	ft_isdigit(int m)
{
	if (m > 47 && m < 58)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int		i;
	char	c;

	i = ft_isdigit('9');
	c = i + '0';
	write(1, &c, 1);
	return (0);
}*/
