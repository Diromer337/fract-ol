/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:49:58 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:50:01 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		move(int keycode, t_fractol *fractol)
{
	short	offset;

	offset = 40;
	if (keycode == ARROW_DOWN)
		fractol->offset_y += -offset;
	else if (keycode == ARROW_UP)
		fractol->offset_y += offset;
	else if (keycode == ARROW_LEFT)
		fractol->offset_x += offset;
	else if (keycode == ARROW_RIGHT)
		fractol->offset_x += -offset;
}

int				key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == MAIN_PAD_R)
		fractol->max = 50;
	else if (keycode == MAIN_PAD_H)
		fractol->menu = (!fractol->menu) ? 1 : 0;
	else if (keycode == MAIN_PAD_ESC)
		exit(0);
	else if (keycode == MAIN_PAD_K)
		fractol->depth = (!fractol->depth) ? 1 : 0;
	else if (keycode == MAIN_PAD_SPACE)
		fractol->julia_static = (!fractol->julia_static) ? 1 : 0;
	else if (keycode == NUM_PAD_PLUS)
		fractol->color_shift += 1;
	else if (keycode == NUM_PAD_MINUS)
		fractol->color_shift -= 1;
	move(keycode, fractol);
	draw_fractol(fractol);
	return (1);
}
