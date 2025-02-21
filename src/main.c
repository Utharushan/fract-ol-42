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
	ft_printf("Usage: ./fractol <fractal_type>\n");
	ft_printf("Available fractals: mandelbrot, julia\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;

	if (argc != 2)
		show_usage();
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
		init_fractol(&fractal, 0);
	else if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
		init_fractol(&fractal, 1);
	else
		show_usage();
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
