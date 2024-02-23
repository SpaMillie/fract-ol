/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:27:22 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/13 21:27:28 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}*/

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
/*
static int	ft_numlen(int n)
{
	int	j;
	int	i;

	i = 0;
	j = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		j = j * 10;
		i--;
	}
	return (j);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		temp_n;
	int		i;
	int		j;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	temp_n = n;
	i = 0;
	j = ft_numlen(n);
	while (j > 0)
	{
		temp_n = temp_n / j;
		ft_putchar_fd(temp_n + '0', fd);
		temp_n = n % j;
		j = j / 10;
	}
}

int	main(void)
{
	int	fd = open("/Users/mspasic/Libft/File.txt", O_RDWR);
	ft_putnbr_fd(32344, fd);
	return (0);
}*/
