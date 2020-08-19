/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:49:23 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:49:25 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_fractol *fractol, t_complex z, t_complex c, int *i)
{
	double	n;
	double	t;

	t = 0;
	(void)c;
	n = z.real * z.real + z.image * z.image;
	while (++(*i) < fractol->max && n < 4)
	{
		t = z.real;
		z.real = t * t - z.image * z.image + fractol->julia.real;
		z.image = 2 * z.image * t + fractol->julia.image;
		n = z.real * z.real + z.image * z.image;
	}
}

void		mandelbrot(t_fractol *fractol, t_complex c, t_complex z, int *i)
{
	double	t;

	t = 0;
	while (++(*i) < fractol->max && (z.real * z.real + z.image * z.image) < 4)
	{
		t = z.real;
		z.real = z.real * z.real - z.image * z.image + c.real;
		z.image = 2 * z.image * t + c.image;
	}
}

void		phoenix(t_fractol *fractol, t_complex c, t_complex z, int *i)
{
	double		n;
	t_complex	t;

	n = z.real * z.real + z.image * z.image;
	t = (t_complex) {.real = 0, .image = 0};
	while (++(*i) < fractol->max && n < 4)
	{
		z.image = 2 * fabs(z.image * z.real) + c.image;
		z.real = t.real - t.image - c.real;
		t.real = z.real * z.real;
		t.image = z.image * z.image;
		n = t.real + t.image;
	}
}
