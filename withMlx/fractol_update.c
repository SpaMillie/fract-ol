// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <MLX42/MLX42.h>

#define WIDTH 1080
#define HEIGHT 1080

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
}
void color_it (int	iter, int i, int j)
{
	if (iter < 3)
		mlx_put_pixel(image, i, j, ft_pixel(38, 115, 157, 200));
	else if (iter < 5)
		mlx_put_pixel(image, i, j, ft_pixel(252, 98, 111, 200));
	else if (iter < 10)
		mlx_put_pixel(image, i, j, ft_pixel(255, 210, 73, 200));
	else
		mlx_put_pixel(image, i, j, ft_pixel(36, 17, 12, 200));
}

int is_it_mandelbrot (double x0, double y0, int i, int j)
{
	double	temp;
	int		max_iter;
	int		iter;
	complex Z;
	
	Z.real = 0;
	Z.imag = 0;
	iter = 0;
	max_iter = 1000;
	while ((Z.real * Z.real) + (Z.imag * Z.imag) <= 2 * 2 && iter < max_iter)
	{
		temp = Z.real * Z.real - Z.imag * Z.imag  + x0;
		Z.imag = 2 * Z.real * Z.imag + y0;
		Z.real = temp;
		iter++;
	}
	if (iter == max_iter)
		return (1);
	else
		color_it(iter, i, j);
	return (0);
}

int	is_it_julia (double cx, double cy, int i, int j)
{
	double	temp;
	int		max_iter;
	int		iter;
	double	R;
	complex	Z;
	
	iter = 0;
	max_iter = 1000;
	R = sqrt(cx * cx + cy * cy);
	while ((Z.real * Z.real) + (Z.imag * Z.imag) <= R * R && iter < max_iter)
	{
		temp = Z.real * Z.real - Z.imag * Z.imag;
		Z.imag = 2 * Z.real * Z.imag + cy;
		Z.real = temp + cx;
		iter++;
	}
	if (iter == max_iter)
		return (1);
	else
		color_it(iter, i, j);
	return (0);
}

void	julia(void)
{
	double	cx;
	double	cy;
	int		result;
	int		i;
	int		j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)		
		{
			cx = (double)i / 1080.0 * R * R - R;
			cy = (double)j / 1080.0 * 4.0 - 2.0;
			result = is_it_mandelbrot(x0, y0, i, j);
			if (result == 1)
				mlx_put_pixel(image, i, j, ft_pixel(254, 175, 160, 200));
			j++;
		}
		i++;
	}
}

void	mandelbrot(void)
{
	double	x0; 
	double	y0;
	int		result;
	int		i;
	int		j;
	// double	scale_factor = zoom();

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)		
		{
			x0 = (double)i / 1080.0 * 4.0 - 2.0;
			y0 = (double)j / 1080.0 * 4.0 - 2.0;
			result = is_it_mandelbrot(x0, y0, i, j);
			if (result == 1)
				mlx_put_pixel(image, i, j, ft_pixel(254, 175, 160, 200));
			j++;
		}
		i++;
	}
}

void	fillimage(int set)
{
	if (set == 1)
		mandelbrot();
	else
		julia();
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
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
	return(0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	if (i < n)
		return (-str2[i]);
	return (0);
}

int	error_checking(int result, char *str1, char *str2)
{
	mlx_t	*mlx;

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

}

int	create_window(char *str1, char *str2)
{
	mlx_t	*mlx;
	int		error;

	error = 0;
	if(!(mlx = mlx_init(1080, 1080, "Fractals", false)))
		error++;
	if (!(image = mlx_new_image(mlx, 1080, 1080)))
	{
		mlx_close_window(mlx);
		error++;
	}
	
	
	mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_scroll_hook(mlx, zoom, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return(0)
}

int	input_error(int	error_type)
{
	if (error_type == 1)
		write(1, "Something went terribly wrong.\n", 32);
	else
	{
		write(1, "Error: Invalid argument.\n", 26);
		write(1, "Try 'Mandelbrot' or 'Julia' or 'Julia number number'", 53);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int	result;

	if (argc == 2)
	{
		result = ft_strncmp(argv[1], "Mandelbrot", 11);
		if (result != 0)
			result = ft_strncmp(argv[1], "Julia", 6);
		if (result == 0 && !create_window(NULL, NULL))
			return (0);
		else
			input_error(0);
	}
	else if (argc == 4)
	{
		result = ft_strncmp(argv[1], "Julia", 6);
		if (result == 0 && !create_window(argv[2], argv[3]))
			create_window(argv[2], argv[3]);
		else
			input_error(0);
	}
	else
		input_error(0);
}

