/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:49:10 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/17 18:20:02 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r')
		return (1);
	if (c == ' ' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	else
		return (0);
}

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned long	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = ft_sign(str[i]);
	if (sign != 0)
		i++;
	while (ft_isnum(str[i]) == 1)
	{
		num = num * 10 + (str[i++] - '0');
		if (sign == -1 && num > 9223372036854775808ULL)
			return (0);
		if ((sign == 1 || sign == 0) && num > 9223372036854775807)
			return (-1);
	}
	if (sign != 0 && num != 0)
		return (sign * num);
	return (num);
}
