/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:02:00 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/19 19:18:21 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <MLX42/MLX42.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_params
{
	double		xdelta;
	double		ydelta;
	double		x0;
	double		y0;
	int			max_iter;
	double		scale;
	mlx_image_t	*image;
	mlx_t		*mlx;
	char		c;
	t_complex	r_and_i;
}	t_params;