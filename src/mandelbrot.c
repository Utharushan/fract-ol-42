/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:23:13 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:23:13 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	int			iteration;
	t_complex	z;
	double		temp;

	z.re = 0;
	z.im = 0;
	iteration = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iteration < MAX_ITER)
	{
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iteration++;
	}
	return (iteration);
}
