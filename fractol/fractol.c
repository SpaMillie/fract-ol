/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:56:54 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/19 20:13:59 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	is_it_julia(int i, int j, t_params *params)
{
	double	temp;
	int		iter;

	params->y0 = -(params->y0);
	iter = 0;
	while ((params->x0 * params->x0) + (params->y0 * params->y0) <= 4 && \
	iter < params->max_iter)
	{
		temp = params->x0 * params->x0 - params->y0 * params->y0;
		params->y0 = 2 * params->x0 * params->y0 + params->r_and_i.imag;
		params->x0 = temp + params->r_and_i.real;
		iter++;
	}
	if (iter == params->max_iter)
		return (iter);
	else
		color_it_inside(iter, i, j, params);
	return (0);
}

void	julia(t_params *params)
{
	double		result;
	int			i;
	int			j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)
		{
			params->x0 = ((double)i / 1080.0 * 4.0 - 2.0) * params->scale;
			params->y0 = ((double)j / 1080.0 * 4.0 - 2.0) * params->scale;
			result = is_it_julia(params->x0, -(params->y0), i, j, params);
			if (result != 0)
				color_it_inside(result, i, j, params);
			j++;
		}
		i++;
	}
}

int	is_it_mandelbrot(int i, int j, t_params *params)
{
	double		temp;
	int			iter;
	t_complex	z;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while ((z.real * z.real) + (z.imag * z.imag) <= 2 * 2 && \
	iter < params->max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + params->x0;
		z.imag = 2 * z.real * z.imag + params->y0;
		z.real = temp;
		iter++;
	}
	if (iter == params->max_iter)
		return (1);
	else
		color_it_outside(iter, i, j, params);
	return (0);
}

void	mandelbrot(t_params *params)
{
	int		result;
	int		i;
	int		j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)
		{
			params->x0 = ((double)i / 1080.0 * 4.0 - 2.0) * params->scale;
			params->y0 = ((double)j / 1080.0 * 4.0 - 2.0) * params->scale;
			result = is_it_mandelbrot(i, j, params);
			if (result == 1)
				mlx_put_pixel(params->image, i, j, \
				ft_pixel(254, 175, 160, 200));
			j++;
		}
		i++;
	}
}

void	fillimage(char set, char *str1, char *str2, t_params *params)
{
	params->c = set;
	if (!str1)
	{
		params->r_and_i.real = 0;
		params->r_and_i.imag = 0;
	}
	else
	{
		params->r_and_i.real = ft_atof(str1);
		params->r_and_i.imag = ft_atof(str2);
	}
	if (set == 'M')
		mandelbrot(params);
	else
		julia(params);
}
