/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colouring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:14:19 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/19 20:16:57 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	color_it_outside(int iter, int i, int j, t_params *params)
{
	if (iter < 3)
		mlx_put_pixel(params->image, i, j, ft_pixel(38, 115, 157, 200));
	else if (iter < 5)
		mlx_put_pixel(params->image, i, j, ft_pixel(252, 98, 111, 200));
	else if (iter < 10)
		mlx_put_pixel(params->image, i, j, ft_pixel(255, 210, 73, 200));
	else
		mlx_put_pixel(params->image, i, j, ft_pixel(36, 17, 12, 200));
}

void	color_it_inside(double iter, int i, int j, t_params *params)
{
	if (iter < 10)
		mlx_put_pixel(params->image, i, j, ft_pixel(221, 97, 55, 200));
	else if (iter < 25)
		mlx_put_pixel(params->image, i, j, ft_pixel(239, 171, 104, 200));
	else if (iter < 30)
		mlx_put_pixel(params->image, i, j, ft_pixel(253, 251, 118, 200));
	else if (iter < 50)
		mlx_put_pixel(params->image, i, j, ft_pixel(227, 169, 96, 200));
	else if (iter < 70)
		mlx_put_pixel(params->image, i, j, ft_pixel(82, 148, 107, 200));
	else if (iter < 90)
		mlx_put_pixel(params->image, i, j, ft_pixel(79, 133, 154, 200));
	else if (iter < 100)
		mlx_put_pixel(params->image, i, j, ft_pixel(108, 182, 177, 200));
	else if (iter < 200)
		mlx_put_pixel(params->image, i, j, ft_pixel(255, 144, 31, 200));
	else if (iter < 400)
		mlx_put_pixel(params->image, i, j, ft_pixel(255, 41, 117, 200));
	else if (iter < 600)
		mlx_put_pixel(params->image, i, j, ft_pixel(199, 0, 181, 200));
	else if (iter < 800)
		mlx_put_pixel(params->image, i, j, ft_pixel(176, 0, 255, 200));
	else
		mlx_put_pixel(params->image, i, j, ft_pixel(0, 219, 150, 200));
}
