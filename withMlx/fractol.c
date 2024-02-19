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

// #define WIDTH 1080
// #define HEIGHT 1080

static mlx_image_t* image;
static double	scale_factor;

// -----------------------------------------------------------------------------

typedef struct s_complex {
	double	real;
	double	imag;
} t_complex;

typedef	struct s_params {
	double	xdelta;
	double	ydelta;
	double	x0;
	double	y0;
} t_params;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
void color_it_outside (int	iter, int i, int j)
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

void color_it_inside (double iter, int i, int j)
{
	if (iter < 10)
		mlx_put_pixel(image, i, j, ft_pixel(221, 97, 55, 200));
	else if (iter < 25)
		mlx_put_pixel(image, i, j, ft_pixel(239, 171, 104, 200));
	else if (iter < 30)
		mlx_put_pixel(image, i, j, ft_pixel(253, 251, 118, 200));
	else if (iter < 50)
		mlx_put_pixel(image, i, j, ft_pixel(227, 169, 96, 200));
	else if (iter < 70)
		mlx_put_pixel(image, i, j, ft_pixel(82, 148, 107, 200));
	else if (iter < 90)
		mlx_put_pixel(image, i, j, ft_pixel(79, 133, 154, 200));
	else if (iter < 100)
		mlx_put_pixel(image, i, j, ft_pixel(108, 182, 177, 200));
	else if (iter < 200)
		mlx_put_pixel(image, i, j, ft_pixel(255, 144, 31, 200));
	else if (iter < 400)
		mlx_put_pixel(image, i, j, ft_pixel(255, 41, 117, 200));
	else if (iter < 600)
		mlx_put_pixel(image, i, j, ft_pixel(199, 0, 181, 200));
	else if (iter < 800)
		mlx_put_pixel(image, i, j, ft_pixel(176, 0, 255, 200));
	else
		mlx_put_pixel(image, i, j, ft_pixel(0, 219, 150, 200));
}

int is_it_mandelbrot (double x0, double y0, int i, int j)
{
	double		temp;
	int			max_iter;
	int			iter;
	t_complex	Z;
	
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
		color_it_outside(iter, i, j);
	return (0);
}

double	is_it_julia (double Z_real, double Z_imag, int i, int j, t_complex c)
{
	double	temp;
	int		max_iter;
	int		iter;
	// double	magnitude;
	
	iter = 0;
	max_iter = 1000;
	while ((Z_real * Z_real) + (Z_imag * Z_imag) <= 4 && iter < max_iter)
	{
		temp = Z_real * Z_real - Z_imag * Z_imag;
		Z_imag = 2 * Z_real * Z_imag + c.imag;
		Z_real = temp + c.real;
		iter++;
	}
	// magnitude = (Z_real * Z_real) + (Z_imag * Z_imag);
	if (iter == max_iter)
		return (iter);
		// return (iter + 1 - (log(magnitude)));
	else
		color_it_inside(iter, i, j);
	return (0);
}

void	julia(t_complex C, t_params *params)
{
	double		result;
	int		i;
	int		j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1080)		
		{
			printf("julia: %f\n", scale_factor);
			params->x0 = ((double)i / 1080.0 * 4.0 - 2.0) * scale_factor;
			params->y0 = ((double)j / 1080.0 * 4.0 - 2.0) * scale_factor;
			result = is_it_julia(params->x0, -(params->y0), i, j, C);
			if (result != 0)
				color_it_inside(result, i, j);
			j++;
		}
		i++;
	}
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
			printf("mndelbrot: %f\n", scale_factor);
			params->x0 = ((double)i / 1080.0 * 4.0 - 2.0) * scale_factor;
			params->y0 = ((double)j / 1080.0 * 4.0 - 2.0) * scale_factor;
			result = is_it_mandelbrot(params->x0, params->y0, i, j);
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

void	fillimage(char set, char *str1, char *str2, t_params *params)
{
	t_complex	c;

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
		mandelbrot(params);
	else
		julia(c, params);
}

// void	erase_image(void)
// {
// 	double	x0; 
// 	double	y0;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < 1080)
// 	{
// 		j = 0;
// 		while (j < 1080)		
// 		{
// 			x0 = (double)i / 1080.0 * 4.0 - 2.0;
// 			y0 = (double)j / 1080.0 * 4.0 - 2.0;
// 			mlx_put_pixel(image, i, j, ft_pixel(0, 0, 0, 0));
// 			j++;
// 		}
// 		i++;
// 	}
// }	

void zoom (double xdelta, double ydelta, void *param)
{
	t_params *params = (t_params*)param;
	
	ydelta *= 10;
	// erase_image();
	if (ydelta < 0)
	{
		scale_factor = scale_factor - 0.25;
		if (scale_factor == 0)
			scale_factor = scale_factor - 0.05;
	}
	else if (ydelta > 0)
	{
		scale_factor = scale_factor + 0.25;
		if (scale_factor == 0)
			scale_factor = scale_factor + 0.05;
	}
	printf("zoom: %f\n", scale_factor);
	mandelbrot(params);
}

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

/*

typedef struct s_params {
	double xdelta;
	double ydelta;
	double scale_factor;
} t_params
double zoom (t_params *params)
{
	double 	a;
	int		y_ydel;
	mlx_t	*mlx;
	
	mlx = param;
	ydelta *= 10;
	a = 40;
	y_ydel = (int) ydelta;
	erase_image();
	if (ydelta < 0)
		a = a - 10;
	else if (ydelta > 0)
		a = a + 10;
	return (a);
}

*/

int	some_error(void);

int	create_window(char set, char *str1, char *str2, t_params *params)
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
	fillimage(set, str1, str2, params);
	mlx_scroll_hook(mlx, zoom, params);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return(0);
}

int	some_error(void)
{
	write(1, "Something went wrong.\n", 23);
	write(1, "Try again?\n", 12);
	write(1, "Valid arguments:'Mandelbrot', 'Julia (num1) (num2)\n", 52);
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

// int	main(void)
// {
// 	char *str = "Mandelbrot";
// 	int	result;

// 	result = ft_strncmp(str, "Mandelbrot", 11);
// 	if (result != 0)
// 		result = ft_strncmp(str, "Julia", 6);
// 	if (result == 0 && create_window(str[0], NULL, NULL) == 0)
// 		return (0);	
// 	else
// 		some_error();
// 	return(0);
// }

void	init_params(t_params *params)
{
	params->xdelta = 0;
	params->ydelta = 0;
	params->x0 = 0;
	params->y0 = 0;
}

int main(int argc, char **argv)
{
	int			result;
	t_params	params;

	scale_factor = 1;
	if (argc == 2)
	{
		init_params(&params);
		result = ft_strncmp(argv[1], "Mandelbrot", 11);
		if (result != 0)
			result = ft_strncmp(argv[1], "Julia", 6);
		if (result == 0 && create_window(argv[1][0], NULL, NULL, &params) == 0)
			return (0);
	}
	else if (argc == 4)
	{
		result = ft_strncmp(argv[1], "Julia", 6);
		result += check_if_valid(argv[2]) + check_if_valid(argv[3]);
		if (result == 0 && create_window(argv[1][0], argv[2], argv[3], &params) == 0)
			return (0);
	}
	some_error();
	return (0);
}

