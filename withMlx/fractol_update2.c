// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>
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

int	is_it_julia (double cx, double cy, int i, int j, complex c)
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
		return (iter);
	else
		color_it(iter, i, j);
	return (0);
}

void	julia(complex C, double x0, double y0)
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
			x0 = (double)i / 1080.0 * 4.0 - 2.0;
			y0 = (double)j / 1080.0 * 4.0 - 2.0;
			result = is_it_julia(x0, y0, i, j, C);
			if (result != 0)
				color_it(result, i, j);
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

int	check_sign (char c)
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

void	fillimage(char set, char *str1, char *str2)
{
	complex	c;

	if (!str1)
	{
		c.real = 0;
		c.imag = 0;
	}
	else
	{
		c.real = ft_atof(str1);
		c.imag = ft_atof(str2);
	}
	if (set == 'M')
		mandelbrot();
	else
		julia(c, 0.00, 0.00);
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

int	create_window(char set, char *str1, char *str2)
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
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		error++;
	}
	if (error != 0)
		return (some_error());
	mlx_loop_hook(mlx, ft_hook, mlx);
	// mlx_scroll_hook(mlx, zoom, mlx);
	mlx_loop(mlx);
	fillimage(set, str1, str2);
	mlx_terminate(mlx);
	return(0);
}

int	some_error(void)
{
	write(1, "Something went wrong.\n", 23);
	write(1, "Try again?\n", 12);
	write(1, "Valid arguments:'Mandelbrot', 'Julia (num1) (num2)", 51);
	return (1);
}
int	check_if_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '.')
		{
			j++;
			i++;
		}
		else
			return (1);
	}
	if (j < 2 && ft_strlen(str) < 64)
		return (0);
	write(1, "Please be reasonable.\n", 23);
	return (1);
}

int main(int argc, char **argv)
{
	int		result;

	if (argc == 2)
	{
		result = ft_strncmp(argv[1], "Mandelbrot", 11);
		if (result != 0)
			result = ft_strncmp(argv[1], "Julia", 6);
		if (result == 0 && create_window(argv[1][0], NULL, NULL) == 0)
			return (0);
	}
	else if (argc == 4)
	{
		result = ft_strncmp(argv[1], "Julia", 6);
		result += check_if_valid(argv[2]) + check_if_valid(argv[3]);
		if (result == 0 && create_window(argv[1][0], argv[2], argv[3]) == 0)
			return (0);
	}
	some_error();
	return (0);
}

