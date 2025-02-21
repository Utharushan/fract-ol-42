/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:17:55 by tuthayak          #+#    #+#             */
/*   Updated: 2025/02/21 11:17:55 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libftprintf/inc/libft.h"
# include "../libftprintf/inc/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		type;
	double	zoom;
	double	offset_x;
	double	offset_y;
	t_complex	julia_c;
}	t_fractol;

/* Initialization */
void	init_fractol(t_fractol *fractal, int type, double julia_re, double julia_im);
void	render_fractal(t_fractol *fractal);

/* Mandelbrot */
int		mandelbrot(t_complex c);

/* Julia */
int		julia(t_complex c, t_complex param);

/* Hooks */
int		handle_key(int keycode, t_fractol *fractal);
int		handle_mouse(int button, int x, int y, t_fractol *fractal);
int		close_window(t_fractol *fractal);

/* Utils */
void	put_pixel(t_fractol *fractal, int x, int y, int color);
void	show_error(char *msg);

#endif
