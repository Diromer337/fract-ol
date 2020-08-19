/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:49:47 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:49:48 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(t_fractol *fractol)
{
	fractol->julia = (t_complex){.real = 0.403333, .image = 0.273333};
	fractol->type = JULIA;
	fractol->formula = julia;
	fractol->max = 200;
}

t_fractol		init_fractol(char *type)
{
	t_fractol	fractol;

	fractol.max = 50;
	if (!ft_strcmp(type, "mandelbrot"))
		fractol.formula = mandelbrot;
	else if (!ft_strcmp(type, "julia"))
		init_julia(&fractol);
	else if (!ft_strcmp(type, "phoenix"))
		fractol.formula = phoenix;
	else
		fractol.type = NONE;
	fractol.mlx_ptr = mlx_init();
	fractol.win_ptr = mlx_new_window(fractol.mlx_ptr, WIDTH, HEIGHT, "Fractol");
	fractol.image = init_img(fractol);
	fractol.julia_static = 0;
	fractol.zoom = 250;
	fractol.offset_x = 0;
	fractol.offset_y = 0;
	fractol.color_shift = 0;
	fractol.depth = 1;
	fractol.menu = 0;
	return (fractol);
}
