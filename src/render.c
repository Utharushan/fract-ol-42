/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:41:41 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:41:41 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Maps pixel coordinates to the complex plane
t_complex	map_to_complex(int x, int y, t_fractol *fractal)
{
	t_complex	c;

	c.re = (x - WIDTH / 2.0) * (4.0 / WIDTH) * fractal->zoom
		+ fractal->offset_x;
	c.im = (y - HEIGHT / 2.0) * (4.0 / HEIGHT) * fractal->zoom
		+ fractal->offset_y;
	return (c);
}

// Chooses the correct fractal function and assigns color based on iterations
int	get_fractal_value(t_fractol *fractal, int x, int y)
{
	t_complex	c;
	int			iterations;

	c = map_to_complex(x, y, fractal);
	if (fractal->type == 0)
		iterations = mandelbrot(c);
	else
		iterations = julia(c, fractal->julia_c);
	if (iterations == MAX_ITER)
		return (0x000000);
	return (0x0000FF + (iterations * 255 / MAX_ITER) * 0x010000);
}

// Renders the entire fractal
void	render_fractal(t_fractol *fractal)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_fractal_value(fractal, x, y);
			put_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
