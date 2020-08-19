/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:50:20 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:50:31 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2)
	{
		fractol = init_fractol(argv[1]);
		if (fractol.type == NONE)
		{
			ft_putendl("Usage: ./fractol [FRACTOL_TYPE]");
			ft_putendl("[mandelbrot] [julia] [phoenix]");
			return (1);
		}
		draw_fractol(&fractol);
		mlx_mouse_hook(fractol.win_ptr, mouse_hook, &fractol);
		mlx_hook(fractol.win_ptr, 2, 1 << 9, key_hook, &fractol);
		if (fractol.type == JULIA)
			mlx_hook(fractol.win_ptr, 6, 1 << 8, motion_hook, &fractol);
		mlx_hook(fractol.win_ptr, 17, 0, win_close, &fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
	{
		ft_putendl("Usage: ./fractol [FRACTOL_TYPE]");
		ft_putendl("[mandelbrot] [julia] [phoenix]");
	}
	return (0);
}
