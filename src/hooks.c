/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:29:00 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:29:00 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Handle key press events
int	handle_key(int keycode, t_fractol *fractal)
{
	if (keycode == 65307)
		close_window(fractal);
	return (0);
}
// Handle mouse events
int	handle_mouse(int button, int x, int y, t_fractol *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom *= 1.1;
	else if (button == 5)
		fractal->zoom /= 1.1;
	render_fractal(fractal);
	return (0);
}

// Close the window and clean up resources
int	close_window(t_fractol *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
	return (0);
}
