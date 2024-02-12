// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

// -----------------------------------------------------------------------------

typedef struct {
	double	real;
	double	imag;
} complex;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// void ft_fill(void *param, uint32_t a, uint32_t b)
// {
// 	(void)param;
// 	uint32_t i = 40;
// 	uint32_t y = 40;
// 	a = a + i;
// 	b = b + y;

// 	while (i < a)
// 	{
// 		y = 40;
// 		while (y < b)
// 		{
// 			uint32_t color = ft_pixel(244, 237, 50, 100);
// 			// uint32_t color = ft_pixel(0, 0, 0, 0);
// 			// printf ("color = %d \ni = %d\ny = %d\n", color, i, y);
// 			mlx_put_pixel(image, i, y, color);
// 			y++;
// 		}
// 		i++;
// 	}
// }

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// 	image->instances[0].y -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	image->instances[0].y += 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	image->instances[0].x -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	image->instances[0].x += 5;
}

int is_it_mandelbrot (double x0, double y0, complex Z)
{
	double	temp;
	double	magnitude;

	int max_iter = 1000;
	int iter = 0;

	while ((Z.real * Z.real) + (Z.imag * Z.imag) <= 2 * 2 && iter < max_iter)
	{
		temp = (Z.real * Z.real) - (Z.imag * Z.imag)  + x0;
		Z.imag = ((2 * Z.real) * Z.imag) + y0;
		Z.real = temp;
		iter++;
	}
	if (iter == max_iter)
	{
		return (0);
	}
	return (1);

	// temp = Z.real;
	// Z.real = Z.real * Z.real - Z.imag * Z.imag  + x0;
	// Z.imag = 2 * temp * Z.imag + y0;
	// magnitude = Z.real * Z.real + Z.imag * Z.imag;
	// // printf("%f %f\n", Z.real, Z.imag);
	// if (fabs(magnitude) < 4) //check if it's part of the set
	// 	return (1);
	// return (0);
}

void	ft_fillimage(void)
{
	double	x0; 
	double	y0;
	int		iter;
	int		result;
	int		i;
	int		j;
	double temp;
	complex	Z = {0, 0};
	// double	scale_factor = zoom();

	iter = 0;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		iter = 0;
		while (j < HEIGHT)		
		{
			iter = 0;
			x0 = (double)i / (double)WIDTH * 4.0 - 2.0;
			y0 = (double)j / (double)HEIGHT * 4.0 - 2.0;
			// temp = Z.real;
			// Z.real = Z.real * Z.real - Z.imag * Z.imag  + x0;
			// Z.imag = 2 * temp * Z.imag + y0;
			// printf("%f %f\n", Z.real, Z.imag);
			result = is_it_mandelbrot(x0, y0, Z);
//			printf("%d\n", result);
			if (result == 1)
			{
				mlx_put_pixel(image, i, j, ft_pixel(170, 46, 37, 255));
				printf("%d %d\n", i, j);
			}
			else
				mlx_put_pixel(image, i, j, 0);
			iter++;
			j++;
		}
		i++;
	}
}

// int zoom (double xdelta, double ydelta, void *param)
// {
// 	static double a = 40;
// 	mlx_t *mlx = param;
// 	ydelta *= 10;
// 	int32_t y_ydel = (int) ydelta;
// 	printf("%d\n", y_ydel);
// 	ft_fillimage();
// 	if (ydelta < 0)
// 		a = a - 10;
// 	else if (ydelta > 0)
// 		a = a + 10;
// 	return (a);
// 	// ft_fill(mlx, a, b);
// }

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	// ft_fill(mlx, 88, 88);
	ft_fillimage();
	mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_scroll_hook(mlx, zoom, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

