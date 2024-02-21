/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:23:53 by mspasic           #+#    #+#             */
/*   Updated: 2024/02/21 18:50:13 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	create_window(char set, char *str1, char *str2, t_params *params)
{
	mlx_loop_hook(params->mlx, ft_hook, params->mlx);
	fillimage(set, str1, str2, params);
	mlx_scroll_hook(params->mlx, zoom, params);
	mlx_loop(params->mlx);
	mlx_terminate(params->mlx);
	return (0);
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

int	init_params(t_params *params)
{
	int	error;

	params->xdelta = 0;
	params->ydelta = 0;
	params->x0 = 0;
	params->y0 = 0;
	params->scale = 1.00;
	params->max_iter = 1000;
	error = 0;
	params->mlx = mlx_init(1080, 1080, "Fractals", false);
	if (!(params->mlx))
		error++;
	params->image = mlx_new_image(params->mlx, 1080, 1080);
	if (!(params->image) || \
	(mlx_image_to_window(params->mlx, params->image, 0, 0) == -1))
	{
		mlx_close_window(params->mlx);
		error++;
	}
	if (error != 0)
		return (error);
	return (0);
}

int	main(int argc, char **argv)
{
	int			result;
	t_params	params;

	if (init_params(&params) != 0 || (argc < 2 || argc > 4 || argc == 3))
	{
		some_error();
		return (0);
	}
	else if (argc == 2)
	{
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
		if (result == 0 && \
			create_window(argv[1][0], argv[2], argv[3], &params) == 0)
			return (0);
	}
}
