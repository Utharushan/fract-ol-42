/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:22:22 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:22:22 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Function to show usage instructions
void	show_usage(void)
{
	ft_printf("Usage: ./fractol <fractal_type> [<julia_re> <julia_im>]\n");
	ft_printf("Do not put letters in julia_re and julia_im\n");
	ft_printf("Available fractals: mandelbrot, julia\n");
	ft_printf("Some available parameters for julia:\n");
	ft_printf("(0.3, 0.5), (0.285, 0.01), (-0.7, 0.27015), (-1,476, 0)\n");
	exit(1);
}

// Function to set up the fractal based on user input
void	setup_fractal(int argc, char **argv, t_fractol *fractal)
{
	double	julia_re;
	double	julia_im;

	julia_re = -0.8;
	julia_im = 0.156;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		init_fractol(fractal, 0, 0, 0);
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc == 4)
		{
			julia_re = ft_atof(argv[2]);
			julia_im = ft_atof(argv[3]);
		}
		init_fractol(fractal, 1, julia_re, julia_im);
	}
	else
		show_usage();
}

// Main function
int	main(int argc, char **argv)
{
	t_fractol	fractal;

	if (argc < 2 || (ft_strncmp(argv[1], "julia", 6) == 0
			&& argc != 2 && argc != 4) || (ft_strncmp(argv[1], "mandelbrot",
				11) == 0 && argc != 2))
		show_usage();
	setup_fractal(argc, argv, &fractal);
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	close_window(&fractal);
	return (0);
}
