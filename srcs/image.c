/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:49:37 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:49:38 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		init_img(t_fractol fractol)
{
	t_image	image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	image.img_ptr = mlx_new_image(fractol.mlx_ptr, WIDTH, HEIGHT);
	image.img_data = mlx_get_data_addr(image.img_ptr, &bits_per_pixel,
										&size_line, &endian);
	image.bits_per_pixel = bits_per_pixel;
	image.size_line = size_line;
	return (image);
}
