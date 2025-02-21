/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:23:39 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:23:39 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex c, t_complex param)
{
	int			iteration;
	double		temp;

	iteration = 0;
	while (c.re * c.re + c.im * c.im <= 4 && iteration < MAX_ITER)
	{
		temp = c.re * c.re - c.im * c.im + param.re;
		c.im = 2 * c.re * c.im + param.im;
		c.re = temp;
		iteration++;
	}
	return (iteration);
}
