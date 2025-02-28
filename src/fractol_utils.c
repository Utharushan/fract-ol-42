/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:28:00 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:28:00 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Initializes the fractal struct (julia.re = -0.7, julia.im = 0.27015)
void	init_fractol(t_fractol *fractal, int type,
	double julia_re, double julia_im)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(1);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "fractol");
	if (!fractal->win)
		exit(1);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		exit(1);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_length, &fractal->endian);
	fractal->type = type;
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->julia_c.re = julia_re;
	fractal->julia_c.im = julia_im;
	mlx_key_hook(fractal->win, handle_key, fractal);
	mlx_mouse_hook(fractal->win, handle_mouse, fractal);
	mlx_hook(fractal->win, 17, 0, close_window, fractal);
}

void	put_pixel(t_fractol *fractal, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fractal->addr
			+ (y * fractal->line_length + x * (fractal->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
