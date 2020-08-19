/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:50:38 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:50:40 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		menu(t_fractol *fractol, unsigned color)
{
	short	x;

	x = 15;
	if (!fractol->depth)
		mlx_string_put(fractol->mlx_ptr, fractol->win_ptr,
						WIDTH - 100, 10, color, "Depth: ON");
	else
		mlx_string_put(fractol->mlx_ptr, fractol->win_ptr,
						WIDTH - 100, 10, color, "Depth: OFF");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 10, color,
			"Press 'H' to close help");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 45, color,
			"West, East, North, South : [<-] [->] [^] [v]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 70, color,
			"Zoom : [Mouse wheel]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 95, color,
			"Color shift : [+] [-]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 120, color,
			"Pause mouse motion and zoom : [SPACE]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 145, color,
			"Depth on : [K]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 170, color,
			"Reset depth : [R]");
	mlx_string_put(fractol->mlx_ptr, fractol->win_ptr, x, 205, color,
			"Exit : [ESCAPE]");
}
