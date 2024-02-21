/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:49:19 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/21 11:33:27 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	check_sign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		j;
	double	num;
	double	num_dot;

	i = 0;
	j = 0;
	num = 0.00;
	num_dot = 0.00;
	if (check_sign(str[i]) != 0)
		i++;
	while (str[i + j] != '\0')
	{
		if (j == 0 && str[i] != '.')
			num = num * 10.00 + (str[i++] - '0');
		else if (str[i + j] != '.')
			num_dot = num_dot + (str[j + i] - '0') * pow(0.1, j);
		if (str[i + j] == '.' || j != 0)
			j++;
	}
	if (check_sign(str[0]) == -1 && (num + num_dot) != 0.00)
		return ((num + num_dot) * -1.00);
	return (num + num_dot);
}

void	zoom(double xdelta, double ydelta, void *param)
{
	t_params	*params;

	xdelta = 0;
	params = (t_params *)param;
	ydelta *= 10;
	if (ydelta < 0)
	{
		params->scale = params->scale / 1.1;
		if (params->max_iter > 50 && params->c == 'M')
			params->max_iter = params->max_iter - 50;
	}
	else if (ydelta > 0)
		params->scale = params->scale * 1.1;
	if (params->c == 'M')
		mandelbrot(params);
	else
		julia(params);
}

int	check_number(const char *s1)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;

	i = 0;
	j = 0;
	str1 = (unsigned char *)s1;
	if (str1[i] == '-' || str1[i] == '+')
		i++;
	while (i < ft_strlen(s1) && str1[i] != '\0')
	{
		if ((str1[i] >= '0' && str1[i] <= '9'))
			i++;
		else if (str1[i] == '.')
		{
			j++;
			i++;
		}
		else
			return (0);
	}
	if (j <= 1)
		return (1);
	return (0);
}
