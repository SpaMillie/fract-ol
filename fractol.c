#include <math.h>
#include <stdio.h>

typedef struct {
	double	real;
	double	imag;
} complex;

// complex	calculate_Z(double x, double y)
// {
// 	complex	result;
// 	result.real = x;
// 	result.imag = y;
// }

// int	put_pixels(int P1, int i, int j)
// {
// 	int	Pi;
// 	int Pj;

// 	Pi = P1 + i;
// 	Pj = P1 + j;
// 	// you dont need this just use i and j as pixel coordinates
// 	// since p1 = 0
// }

int is_it_mandelbrot (double x0, double y0, complex Z);

void calculate_0 (int i, int j, int width, int WIDTH, int height, int HEIGHT)
{
	double	x0; 
	double	y0;
	int		iter;
	int		result;
	complex	Z = {0, 0};

	iter = 0;
	while (i < 512 && iter < 1000)
	{
		j = 0;
		while (j < 512 && iter < 1000)		
		{
			x0 = (double)i / (double)WIDTH * (double)width - (double)width / 2;
			y0 = (double)j / (double)HEIGHT * (double)height - (double)height / 2;
			result = is_it_mandelbrot(x0, y0, Z);
			if (result == 1)
				printf("YES!!!");
			else
				printf("no");
			// printf("%f %f %d %d \n", x0, y0, i, j);
			iter++;
			j++;
		}
		i++;
	}
}

int is_it_mandelbrot (double x0, double y0, complex Z)
{
	double	temp;
	double	magnitude;
	
	temp = Z.real;
	Z.real = Z.real * Z.real - Z.imag * Z.imag  + x0;
	Z.imag = 2 * temp * Z.imag + y0;
	magnitude = Z.real * Z.real + Z.imag * Z.imag;
	// printf("%f %f\n", Z.real, Z.imag);
	if (fabs(magnitude) < 4) //check if it's part of the set
		return (1);
	return (0);
}

int	main(void)
{
	int width = 4;
	int	WIDTH = 512;
	int	height = 4;
	int	HEIGHT = 512;
	int i = 0;
	int j = 0;

	calculate_0 (i, j, width, WIDTH, height, HEIGHT);

}