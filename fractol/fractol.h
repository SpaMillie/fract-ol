/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:02:00 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/21 14:27:13 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <unistd.h>
# include <MLX42/MLX42.h>

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

//main.c
int		create_window(char set, char *str1, char *str2, t_params *params);
int		some_error(void);
int		check_if_valid(char *str);
int		init_params(t_params *params);
int		main(int argc, char **argv);
//fractol.c
double	is_it_julia(int i, int j, t_params *params);
void	julia(t_params *params);
int		is_it_mandelbrot(int i, int j, t_params *params);
void	mandelbrot(t_params *params);
void	fillimage(char set, char *str1, char *str2, t_params *params);
//utils.c
void	ft_hook(void *param);
int		check_sign(char c);
double	ft_atof(char *str);
void	zoom(double xdelta, double ydelta, void *param);
int		check_number(const char *s1);
//colouring.c
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	color_it_outside(int iter, int i, int j, t_params *params);
void	color_it_inside(double iter, int i, int j, t_params *params);
#endif
