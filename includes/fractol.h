/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:47:59 by eberta            #+#    #+#             */
/*   Updated: 2020/08/08 19:48:07 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# define HEIGHT 768
# define WIDTH 1366
# define WHITE 0xFFFFFF
# define BLACK (t_color){0, 0, 0, 0}
# define THREADS 8
# include "mlx.h"
# include "math.h"
# include "keys.h"
# include "../libft/libft.h"
# include "pthread.h"

enum				e_fractal{MANDELBROT, JULIA, NONE};

typedef struct		s_image
{
	void			*img_ptr;
	char			*img_data;
	int				bits_per_pixel;
	int				size_line;
}					t_image;

typedef struct		s_complex
{
	double			real;
	double			image;
}					t_complex;

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			image;
	enum e_fractal	type;
	void			(*formula)(struct s_fractol*, t_complex, t_complex, int*);
	char			*data;
	int				x[THREADS];
	int				y[THREADS];
	double			zoom;
	long			offset_x;
	long			offset_y;
	double			max;
	double			min_x;
	double			min_y;
	unsigned short	color_shift;
	t_complex		julia;
	short			julia_static;
	short			depth;
	short			menu;
}					t_fractol;

typedef struct		s_thread
{
	int				id;
	t_fractol		*fractol;
	pthread_t		thread;
}					t_thread;

typedef struct		s_color
{
	int8_t			channel[4];
}					t_color;

t_image				init_img(t_fractol fractol);
int					win_close();
t_fractol			init_fractol(char *type);
void				menu(t_fractol *fractol, unsigned color);
void				phoenix(t_fractol *fractol, t_complex c,
						t_complex z, int *i);
int					mouse_hook(int button, int x, int y, t_fractol *fractol);
void				draw_fractol(t_fractol *fractol);
int					motion_hook(int x, int y, t_fractol *fractol);
t_color				select_color(t_fractol *fractol, int i);
void				put_pixel(t_fractol *fractol, int x, int y, t_color color);
int					key_hook(int keycode, t_fractol *fractol);
void				julia(t_fractol *fractol, t_complex z, t_complex c, int *i);
void				mandelbrot(t_fractol *fractol, t_complex c,
						t_complex z, int *i);
t_fractol			init_fractol(char *type);

#endif
