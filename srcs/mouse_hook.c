/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:50:45 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:50:47 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			win_close(void)
{
	exit(0);
}

int			motion_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->julia_static && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		fractol->julia.real = (x + fractol->offset_x)
								/ fractol->zoom + fractol->min_x;
		fractol->julia.image = (y + fractol->offset_y)
								/ fractol->zoom + fractol->min_y;
		draw_fractol(fractol);
	}
	return (1);
}

void		zoom(int button, int x, int y, t_fractol *fractol)
{
	if (!fractol->depth && button == MOUSE_SCROLL_DOWN)
		fractol->max *= 1.02;
	else if (!fractol->depth)
		fractol->max /= 1.02;
	if (button == MOUSE_SCROLL_UP && !fractol->julia_static)
	{
		fractol->zoom *= 0.8;
		fractol->offset_x = round((fractol->offset_x +
									x - (WIDTH >> 1)) * 0.8);
		fractol->offset_y = round((fractol->offset_y +
									y - (HEIGHT >> 1)) * 0.8);
	}
	else if (!fractol->julia_static)
	{
		fractol->zoom *= 1.25;
		fractol->offset_x = round((fractol->offset_x +
									(WIDTH >> 1) - x) * 1.25);
		fractol->offset_y = round((fractol->offset_y +
									(HEIGHT >> 1) - y) * 1.25);
	}
}

int			mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if ((button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN))
	{
		zoom(button, x, y, fractol);
		draw_fractol(fractol);
	}
	return (1);
}
