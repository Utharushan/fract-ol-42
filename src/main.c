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

void	show_usage(void)
{
	ft_printf("Usage: ./fractol <fractal_type> [<julia_re> <julia_im>]\n");
	ft_printf("Available fractals: mandelbrot, julia\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;
	double		julia_re;
	double		julia_im;

	julia_re = -0.8;
	julia_im = 0.156;
	if (argc < 2 || (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0 && argc != 2 && argc != 4))
		show_usage();
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
		init_fractol(&fractal, 0, 0, 0);
	else if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
	{
		if (argc == 4)
		{
			julia_re = ft_atof(argv[2]);
			julia_im = ft_atof(argv[3]);
		}
		init_fractol(&fractal, 1, julia_re, julia_im);
	}
	else
		show_usage();
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
