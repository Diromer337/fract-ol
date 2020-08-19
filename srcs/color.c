/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:49:03 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:49:05 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int i;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		i = (x * fractol->image.bits_per_pixel >> 3) +
			(y * fractol->image.size_line);
		fractol->image.img_data[i] = color.channel[3];
		fractol->image.img_data[++i] = color.channel[2];
		fractol->image.img_data[++i] = color.channel[1];
		fractol->image.img_data[++i] = color.channel[0];
	}
}

t_color		select_color(t_fractol *fractol, int i)
{
	t_color	color;
	double	t;

	t = (double)i / fractol->max;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
