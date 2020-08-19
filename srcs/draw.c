/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:49:11 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:49:13 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_pixel(t_fractol *fractol, int id)
{
	t_complex	z;
	t_complex	c;
	int			i;
	t_color		color;

	c.real = (double)fractol->x[id] / fractol->zoom + fractol->min_x;
	c.image = (double)fractol->y[id] / fractol->zoom + fractol->min_y;
	z = (t_complex){.real = 0, .image = 0};
	i = -1;
	color = BLACK;
	fractol->formula(fractol, c, z, &i);
	if (i > fractol->max)
		put_pixel(fractol, fractol->x[id], fractol->y[id], color);
	else
		put_pixel(fractol, fractol->x[id], fractol->y[id],
			select_color(fractol, i));
}

void		*render_part(void *thread)
{
	t_thread	*t;

	t = (t_thread*)thread;
	t->fractol->y[t->id] = (HEIGHT / THREADS) * t->id;
	while (t->fractol->y[t->id] < (HEIGHT / THREADS) * (t->id + 1))
	{
		t->fractol->x[t->id] = -1;
		while (++t->fractol->x[t->id] < WIDTH)
		{
			draw_pixel(t->fractol, t->id);
		}
		++t->fractol->y[t->id];
	}
	return (NULL);
}

void		draw_fractol(t_fractol *fractol)
{
	t_thread		thread[THREADS];
	int				i;

	fractol->min_x = ((fractol->offset_x + (WIDTH >> 1)) /
						(fractol->zoom / 2)) / -2;
	fractol->min_y = ((fractol->offset_y + (HEIGHT >> 1)) /
						(fractol->zoom / 2)) / -2;
	i = -1;
	while (++i < THREADS)
	{
		thread[i].id = i;
		thread[i].fractol = fractol;
		pthread_create(&(thread[i].thread), NULL, render_part, &thread[i]);
	}
	while (--i >= 0)
		pthread_join(thread[i].thread, NULL);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
								fractol->image.img_ptr, 0, 0);
	if (!fractol->menu)
		menu(fractol, WHITE);
}
